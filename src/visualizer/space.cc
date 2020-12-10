//
// Created by sujay on 11/17/2020.
//

#include "visualizer/space.h"

galaga::Space::Space(const glm::vec2& top_left_corner, size_t dimensions)
    : top_left_corner_(top_left_corner),
      dimensions_(dimensions),
      battleship_(glm::vec2(
          top_left_corner_[0] + static_cast<float>(dimensions) / 2,
          top_left_corner_[1] + 9 * static_cast<float>(dimensions) / 10)) {
  score_ = 0;
  level_ = 1;

  GenerateEnemies(level_);
}

void galaga::Space::Update() {
  UpdateBullets();
  UpdateEnemies();

  if (enemies_.empty()) {
    NextLevel();
  }

  // Performs end of life behavior for battleship
  if (battleship_.IsDead()) {
    if (battleship_.GetExplosionTimer() != 0) {
      battleship_.DecrementExplosionTimer();
    } else {
      battleship_.Restart();
      Restart();
      GenerateEnemies(level_);
    }
  }
}

void galaga::Space::Draw() const {
  // Sets the background texture
  cinder::gl::Texture2dRef background_texture =
      cinder::gl::Texture2d::create(cinder::loadImage(kBackgroundFilePath));
  ci::gl::draw(background_texture,
               ci::Rectf(top_left_corner_,
                         glm::vec2(top_left_corner_[0] + dimensions_,
                                   top_left_corner_[1] + dimensions_)));

  ci::gl::color(ci::Color::white());
  battleship_.Draw();

  for (const PlayerBullet& bullet : bullets_) {
    bullet.Draw();
  }

  for (const Enemy& enemy : enemies_) {
    enemy.Draw();
  }
}

void galaga::Space::NextLevel() {
  level_++;
  GenerateEnemies(level_);
}

void galaga::Space::GenerateEnemies(size_t level) {
  // Generates 3 more enemies for each level
  for (size_t enemy_index = 0; enemy_index < (level*3); enemy_index++) {
    enemies_.emplace_back(Enemy(
        top_left_corner_[0] +
        (glm::vec2((enemy_index * static_cast<float>(dimensions_)) / (level*3),
                   top_left_corner_[1] + cinder::randFloat(0.2f) *
                                         static_cast<float>(dimensions_)))));
  }
}

void galaga::Space::Restart() {
  bullets_.clear();
  enemies_.clear();
  battleship_.Restart();

  // Writes new highscores to the highscore.txt file
  std::ifstream InputFile(kHighscoreFilePath);
  if(InputFile.is_open())
  {
    size_t highscore;
    InputFile >> highscore;
    if(highscore < score_)
    {
      std::ofstream OutputFile (kHighscoreFilePath);
      OutputFile << score_;
      OutputFile.close();
    }
    InputFile.close();
  }

  score_ = 0;
  level_ = 1;
}

void galaga::Space::BattleshipLeftShoot() {
  // Shoots a bullet if the battleship is still alive
  if (!battleship_.IsDead()) {
    bullets_.emplace_back(PlayerBullet(glm::vec2(
        battleship_.GenerateRectPosition().getCenter()[0],
        battleship_.GenerateRectPosition().getUpperLeft()[1] - kBulletMargin)));
  }
}

void galaga::Space::UpdateBullets() {
  for (size_t index = 0; index < bullets_.size(); index++) {
    // Deletes bullets that leave the bounds
    if ((bullets_[index].GetCenterPosition()[1] -
         bullets_[index].kSpeed) < (top_left_corner_[1])) {
      bullets_.erase(bullets_.begin() + index);
    } else {
      this->bullets_[index].Update();
    }
  }
}

void galaga::Space::UpdateEnemies() {
  for (size_t enemy_index = 0; enemy_index < enemies_.size(); enemy_index++) {
    // Performs end of life behavior for an enemy
    if (!enemies_[enemy_index].IsDead()) {
      enemies_[enemy_index].Update();
    } else if (enemies_[enemy_index].GetExplosionTimer() != 0) {
      enemies_[enemy_index].DecrementExplosionTimer();
    } else {
      enemies_.erase(enemies_.begin() + enemy_index);
      return;
    }

    // Destroys bullets that leave the bounds
    if ((this->enemies_[enemy_index].GenerateRectPosition().getLowerLeft()[1] -
         this->enemies_[enemy_index].kSpeed) >
        (this->top_left_corner_[1] + dimensions_)) {
      enemies_[enemy_index].Destroy();
      return;
    }

    // Checks for enemy and battleship collisions and destroys each
    if (!enemies_[enemy_index].IsDead() && battleship_.GenerateRectPosition().intersects(
            enemies_[enemy_index].GenerateRectPosition())) {
      enemies_[enemy_index].Destroy();
      battleship_.Destroy();
      return;
    }

    // Checks for bullet and enemy collisions, destroys each, and increments score
    for (size_t bullet_index = 0; bullet_index < bullets_.size();
         bullet_index++) {
      if (!enemies_[enemy_index].IsDead() && bullets_[bullet_index].GenerateRectPosition().intersects(
              enemies_[enemy_index].GenerateRectPosition())) {
        bullets_.erase(bullets_.begin() + bullet_index);
        enemies_[enemy_index].Destroy();
        score_ += kScoreIncrement;
        return;
      }
    }
  }
}

galaga::Battleship& galaga::Space::GetBattleship() {
  return battleship_;
}
size_t galaga::Space::GetScore() const {
  return score_;
}
size_t galaga::Space::GetLevel() const {
  return level_;
}
const std::vector<galaga::Enemy>& galaga::Space::GetEnemies() const {
  return enemies_;
}
