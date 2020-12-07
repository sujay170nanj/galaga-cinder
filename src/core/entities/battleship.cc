//
// Created by sujay on 11/17/2020.
//

#include "core/entities/battleship.h"

galaga::Battleship::Battleship(const glm::vec2& position)
    : center_position_(position) {
  lives_ = 3;
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));
}

void galaga::Battleship::MoveRight() {
  center_position_[0] += kSpeed;
}

void galaga::Battleship::MoveLeft() {
  center_position_[0] -= kSpeed;
}

void galaga::Battleship::Draw() const {
  ci::gl::draw(texture_, GenerateRectPosition());
}

void galaga::Battleship::Destroy() {
  if (lives_ > 0) {
    lives_--;
  } else {

  }
}

size_t galaga::Battleship::GetLives() const {
  return lives_;
}

cinder::Rectf galaga::Battleship::GenerateRectPosition() const {
  cinder::Rectf drawRect(center_position_[0] - kBattleshipDimensions / 2,
                         center_position_[1] - kBattleshipDimensions / 2,
                         center_position_[0] + kBattleshipDimensions / 2,
                         center_position_[1] + kBattleshipDimensions / 2);

  return drawRect;
}
