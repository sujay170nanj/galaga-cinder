//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"


namespace galaga {

class Enemy {
 public:
  static constexpr float kVerticalSpeed = 0.5;

  Enemy(const glm::vec2& position);

  void Update();

  void Draw() const;

  Enemy& Enemy::operator=(const Enemy& source);

  void Destroy();

  cinder::Rectf GenerateRectPosition() const;

  bool IsDead() const;

  size_t GetExplosionTimer() const;

  void DecrementExplosionTimer();

 private:
  static constexpr size_t kEnemyDimensions = 40;
  const std::string kSpriteOneFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite1.png";
  const std::string kSpriteTwoFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite2.png";
  const std::string kSpriteThreeFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite3.png";
  const std::string kExplosionFilePath = "D:\\Downloads\\Cinder\\my-projects\\final-project-sujay170nanj\\resources\\explosion_sprite.png";

  glm::vec2 center_position_;
  cinder::gl::Texture2dRef texture_;
  bool is_dead_;
  size_t explosion_timer_;
};

}  // namespace galaga
