//
// Created by sujay on 11/17/2020.
//

#include "core/entities/battleship.h"

galaga::Battleship::Battleship(const glm::vec2& position)
    : center_position_(position),
      initial_position_(position) {
  is_dead_ = false;
  lives_ = 3;
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));
  explosion_timer_ = 40;
}

void galaga::Battleship::MoveRight() {
  if (!is_dead_) {
    center_position_[0] += kSpeed;
  }
}

void galaga::Battleship::MoveLeft() {
  if (!is_dead_) {
    center_position_[0] -= kSpeed;
  }
}

void galaga::Battleship::Draw() const {
  ci::gl::draw(texture_, GenerateRectPosition());
}

void galaga::Battleship::Destroy() {
  if (lives_ > 1) {
    lives_--;
  } else {
    is_dead_ = true;
    // Sets the sprite to the explosion
    texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kExplosionFilePath));
  }
}

void galaga::Battleship::Restart() {
  lives_ = 3;
  center_position_ = initial_position_;
  explosion_timer_ = 40;
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));
  is_dead_ = false;
}

void galaga::Battleship::DecrementExplosionTimer() {
  explosion_timer_--;
}

size_t galaga::Battleship::GetLives() const {
  return lives_;
}

cinder::Rectf galaga::Battleship::GenerateRectPosition() const {
  // Rectangle made with four corners of sprite
  cinder::Rectf drawRect(center_position_[0] - kBattleshipDimensions / 2,
                         center_position_[1] - kBattleshipDimensions / 2,
                         center_position_[0] + kBattleshipDimensions / 2,
                         center_position_[1] + kBattleshipDimensions / 2);

  return drawRect;
}
bool galaga::Battleship::IsDead() const {
  return is_dead_;
}
size_t galaga::Battleship::GetExplosionTimer() const {
  return explosion_timer_;
}
