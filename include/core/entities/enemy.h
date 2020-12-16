//
// Created by sujay on 11/17/2020.
//

#pragma once

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"


namespace galaga {

class Enemy {
 public:
  // The vertical speed of an enemy
  static constexpr float kSpeed = 0.5;

  /**
   * Creates an enemy with a random sprite
   *
   * @param position to start at
   */
  Enemy(const glm::vec2& position);

  /**
   * Updates the position of the enemy
   */
  void Update();

  /**
   * Displays the enemy at the current position
   */
  void Draw() const;

  /**
   * Copy assignment operator to be used in destruction of the enemy
   *
   * @param source being copied
   * @return reference of enemy
   */
  Enemy& Enemy::operator=(const Enemy& source);

  /**
   * Sets the enemy to be dead and changes the texture
   */
  void Destroy();

  /**
   * Creates a Rectf object based on the position and dimensions of the enemy
   *
   * @return Rectf representing a hitbox
   */
  cinder::Rectf GenerateRectPosition() const;

  /**
   * Decreases explosion timer by one
   */
  void DecrementExplosionTimer();

  bool IsDead() const;

  size_t GetExplosionTimer() const;

 private:
  // Square dimensions of the enemy
  static constexpr size_t kEnemyDimensions = 40;
  // First file path for the enemy sprite
  const std::string kSpriteOneFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite1.png";
  // Second file path for the enemy sprite
  const std::string kSpriteTwoFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite2.png";
  // Third file path for the enemy sprite
  const std::string kSpriteThreeFilePath =
      "D:\\Downloads\\Cinder\\my-projects\\final-project-"
      "sujay170nanj\\resources\\enemy_sprite3.png";
  // File path for the explosion sprite
  const std::string kExplosionFilePath = "D:\\Downloads\\Cinder\\my-projects\\final-project-sujay170nanj\\resources\\explosion_sprite.png";

  glm::vec2 center_position_;
  cinder::gl::Texture2dRef texture_;
  bool is_dead_;
  size_t explosion_timer_;
};

}  // namespace galaga
