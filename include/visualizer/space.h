//
// Created by sujay on 11/17/2020.
//

#pragma once

#include <core/entities/battleship.h>
#include <core/hitbox.h>
#include <core/particles/player_bullet.h>

#include "cinder/gl/gl.h"

namespace galaga {

class Space {
 public:
  Space(const glm::vec2& top_left_corner, size_t dimensions,
        const std::vector<Hitbox>& hitboxes = std::vector<Hitbox>());

  void Update();

  void Draw() const;

  void Clear();

  void BattleshipLeftShoot();

  Battleship& GetBattleship();

 private:
  const size_t kBulletMargin = 5;

  const std::string kBackgroundFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\background.gif";

  glm::vec2 top_left_corner_;
  std::vector<Hitbox> hitboxes_;
  size_t dimensions_;
  Battleship battleship_;
  std::vector<PlayerBullet> bullets_;
};

}  // namespace galaga
