//
// Created by sujay on 11/17/2020.
//

#pragma once

#include <core/hitbox.h>

#include "cinder/gl/gl.h"

namespace galaga {

class PlayerBullet {
 public:
  PlayerBullet(const glm::vec2& position);

  void Update();

  void Draw() const;

  cinder::Rectf GenerateRectPosition() const;

 private:
  static constexpr size_t kBulletDimensions = 20;
  static constexpr size_t kSpeed = 50;
  const std::string kSpriteFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\player_bullet_sprite.png";

  glm::vec2 center_position_;
  Hitbox hitbox_;
};

}  // namespace galaga
