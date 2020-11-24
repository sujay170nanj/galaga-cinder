//
// Created by sujay on 11/17/2020.
//

#include "core/entities/enemy.h"

galaga::Enemy::Enemy(const glm::vec2& position) : center_position_(position) {
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));
}

void galaga::Enemy::Update() {
  center_position_[1] += kSpeed;
}

void galaga::Enemy::Draw() const {
  ci::gl::draw(texture_, GenerateRectPosition());
}

cinder::Rectf galaga::Enemy::GenerateRectPosition() const {
  cinder::Rectf drawRect(center_position_[0] - kEnemyDimensions / 2,
                         center_position_[1] - kEnemyDimensions / 2,
                         center_position_[0] + kEnemyDimensions / 2,
                         center_position_[1] + kEnemyDimensions / 2);

  return drawRect;
}

