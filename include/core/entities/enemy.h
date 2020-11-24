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

  cinder::Rectf GenerateRectPosition() const;

 private:
  static constexpr size_t kSpeed = 5;
  static constexpr size_t kEnemyDimensions = 60;
  const std::string kSpriteFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite.png";

  glm::vec2 center_position_;
  cinder::gl::Texture2dRef texture_;
};

}  // namespace galaga
