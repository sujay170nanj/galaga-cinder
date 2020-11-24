//
// Created by sujay on 11/17/2020.
//

#include "core/particles/player_bullet.h"

galaga::PlayerBullet::PlayerBullet(const glm::vec2& position)
    : center_position_(position) {
}

void galaga::PlayerBullet::Update() {
  center_position_[1] -= kSpeed;
}

void galaga::PlayerBullet::Draw() const {
  cinder::gl::Texture2dRef texture =
      cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));

  ci::gl::draw(texture, GenerateRectPosition());
}

cinder::Rectf galaga::PlayerBullet::GenerateRectPosition() const {
  cinder::Rectf drawRect(center_position_[0] - kBulletDimensions / 2,
                         center_position_[1] - kBulletDimensions / 2,
                         center_position_[0] + kBulletDimensions / 2,
                         center_position_[1] + kBulletDimensions / 2);

  return drawRect;
}

galaga::PlayerBullet& galaga::PlayerBullet::PlayerBullet::operator=(const PlayerBullet& source) {
  this->center_position_ = source.center_position_;
  return *this;
}


const glm::vec2& galaga::PlayerBullet::GetCenterPosition() const {
  return center_position_;
}

