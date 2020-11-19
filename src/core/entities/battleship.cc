//
// Created by sujay on 11/17/2020.
//

#include "core/entities/battleship.h"

galaga::Battleship::Battleship(const glm::vec2& position)
    : center_position_(position) {
}

void galaga::Battleship::MoveRight() {
  center_position_[0] += kSpeed;
}

void galaga::Battleship::MoveLeft() {
  center_position_[0] -= kSpeed;
}

void galaga::Battleship::LeftShoot() {
}

void galaga::Battleship::Draw() const {
  cinder::gl::Texture2dRef texture =
      cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));

  ci::gl::draw(texture, GenerateRectPosition());
}

cinder::Rectf galaga::Battleship::GenerateRectPosition() const {
  cinder::Rectf drawRect(center_position_[0] - kBattleshipDimensions / 2,
                         center_position_[1] - kBattleshipDimensions / 2,
                         center_position_[0] + kBattleshipDimensions / 2,
                         center_position_[1] + kBattleshipDimensions / 2);

  return drawRect;
}
