//
// Created by sujay on 11/17/2020.
//

#include "core/entities/battleship.h"

galaga::Battleship::Battleship(const glm::vec2& position, const Hitbox& hitbox) : center_position_(position), hitbox_(hitbox) {
}

void galaga::Battleship::MoveRight() {
  center_position_[0] += kSpeed;
}

void galaga::Battleship::MoveLeft() {
  center_position_[0] -= kSpeed;
}

void galaga::Battleship::LeftShoot() {

}

void galaga::Battleship::Draw() {
  cinder::gl::Texture2dRef texture = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));

  ci::gl::draw(texture);
}