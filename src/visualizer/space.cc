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
  for (size_t enemy_index = 0; enemy_index < kNumEnemies; enemy_index++) {
    enemies_.emplace_back(Enemy(top_left_corner_[0] + (glm::vec2((enemy_index * static_cast<float>(dimensions)) / kNumEnemies, top_left_corner_[1] + static_cast<float>(dimensions) / 10))));
  }
}

void galaga::Space::Update() {
  for (size_t index = 0; index < bullets_.size(); index++) {
    if ((bullets_[index].GetCenterPosition()[1] - bullets_[index].kSpeed) <
        (top_left_corner_[1])) {
      bullets_.erase(bullets_.begin() + index);
    } else {
      bullets_[index].Update();
    }
  }

  for (Enemy& enemy: enemies_) {
    enemy.Update();
  }
}

void galaga::Space::Draw() const {
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

  for (const Enemy& enemy: enemies_) {
    enemy.Draw();
  }
}

void galaga::Space::Clear() {
  bullets_.clear();
}

void galaga::Space::BattleshipLeftShoot() {
  bullets_.emplace_back(PlayerBullet(glm::vec2(
      battleship_.GenerateRectPosition().getCenter()[0],
      battleship_.GenerateRectPosition().getUpperLeft()[1] - kBulletMargin)));
}

galaga::Battleship& galaga::Space::GetBattleship() {
  return battleship_;
}
