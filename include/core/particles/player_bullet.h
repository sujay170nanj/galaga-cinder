//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/gl/gl.h"

namespace galaga {

class PlayerBullet {
 public:
  // The horizontal speed of the battleship
  static constexpr size_t kSpeed = 10;

  /**
   * Creates a bullet
   *
   * @param position to start at
   */
  PlayerBullet(const glm::vec2& position);

  /**
   * Updates the position of the bullet
   */
  void Update();

  /**
   * Displays the bullet at the current position
   */
  void Draw() const;

  /**
   * Creates a Rectf object based on the position and dimensions of the bullet
   *
   * @return Rectf representing a hitbox
   */
  cinder::Rectf GenerateRectPosition() const;

  /**
   * Copy assignment operator to be used in destruction of the enemy
   *
   * @param source being copied
   * @return reference to bullet
   */
  PlayerBullet& PlayerBullet::operator=(const PlayerBullet& source);

  const glm::vec2& GetCenterPosition() const;

 private:
  // Square dimensions of the bullet
  static constexpr size_t kBulletDimensions = 10;
  // File path for the bullet sprite
  const std::string kSpriteFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\player_bullet_sprite.png";

  glm::vec2 center_position_;
  cinder::gl::Texture2dRef texture_;
};

}  // namespace galaga
