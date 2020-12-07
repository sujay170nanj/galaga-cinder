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
  Space(const glm::vec2& top_left_corner, size_t dimensions);

  void Update();

  void Draw() const;

  void NextLevel();

  void GenerateEnemies(size_t num_enemies);

  void Restart();

  void BattleshipLeftShoot();

  Battleship& GetBattleship();

  size_t GetScore() const;

  size_t GetLevel() const;

 private:
  const size_t kBulletMargin = 5;
  const size_t kScoreIncrement = 50;
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

  void UpdateBullets();
  void UpdateEnemies();
};

}  // namespace galaga
