//
// Created by sujay on 11/17/2020.
//

#pragma once

#include <core/entities/battleship.h>
#include <core/entities/enemy.h>
#include <core/particles/player_bullet.h>

#include "cinder/gl/gl.h"

namespace galaga {

class Space {
 public:
  const std::string kHighscoreFilePath = "D:\\Downloads\\Cinder\\my-projects\\final-project-sujay170nanj\\resources\\highscore.txt";

  /**
   * Creates the space where the battleship, enemies, and bullets will be held
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the sketchpad
   * @param dimensions          the sidelength of the space square
   */
  Space(const glm::vec2& top_left_corner, size_t dimensions);

  /**
   * Updates all elements in the space object
   */
  void Update();

  /**
   * Displays the current state of all the elements in space
   */
  void Draw() const;

  /**
   * Performs the action of the battleship's shooting
   */
  void BattleshipLeftShoot();

  /**
   * Returns a reference to the battleship
   *
   * @return reference to battleship
   */
  Battleship& GetBattleship();

  size_t GetScore() const;

  size_t GetLevel() const;

  const std::vector<Enemy>& GetEnemies() const;

 private:
  // The margin between the battleship and the initial position of the bullet
  const size_t kBulletMargin = 5;
  // The value to increment the score on a kill
  const size_t kScoreIncrement = 50;
  // The file path of the background image
  const std::string kBackgroundFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\background.gif";

  size_t score_;
  size_t level_;
  glm::vec2 top_left_corner_;
  size_t dimensions_;
  Battleship battleship_;
  std::vector<PlayerBullet> bullets_;
  std::vector<Enemy> enemies_;
 private:
  /**
   * Adds more enemies depending on the current level
   *
   * @param level current level
   */
  void GenerateEnemies(size_t level);

  /**
   * Takes the game to the next level
   */
  void NextLevel();

  /**
   * Restarts the game to default values and situation
   */
  void Restart();

  /**
   * Updates all the bullets and performs necessary interactions
   */
  void UpdateBullets();

  /**
   * Updates all the enemies and performs necessary interactions
   */
  void UpdateEnemies();
};

}  // namespace galaga
