//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/gl/gl.h"

namespace galaga {

class Enemy {
 public:
  Enemy(const glm::vec2& position);

  void Update();

  void Draw() const;

  Enemy& Enemy::operator=(const Enemy& source);

  void Destroy();

  cinder::Rectf GenerateRectPosition() const;

 private:
  static constexpr float kVerticalSpeed = 0.5;
  static constexpr size_t kEnemyDimensions = 40;
  const std::string kSpriteFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite.png";
  const std::string kExplosionFilePath = "D:\\Downloads\\Cinder\\my-projects\\final-project-sujay170nanj\\resources\\explosion_sprite.png";


  glm::vec2 center_position_;
  cinder::gl::Texture2dRef texture_;
};

}  // namespace galaga
