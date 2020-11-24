//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/gl/gl.h"

namespace galaga {

class PlayerBullet {
 public:
  static constexpr size_t kSpeed = 50;

  PlayerBullet(const glm::vec2& position);

  void Update();

  void Draw() const;

  cinder::Rectf GenerateRectPosition() const;

  const glm::vec2& GetCenterPosition() const;

  PlayerBullet& PlayerBullet::operator=(const PlayerBullet& source);

 private:
  static constexpr size_t kBulletDimensions = 20;
  const std::string kSpriteFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\player_bullet_sprite.png";

  glm::vec2 center_position_;
};

}  // namespace galaga
