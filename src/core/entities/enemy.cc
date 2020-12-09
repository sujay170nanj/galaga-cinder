//
// Created by sujay on 11/17/2020.
//

#include "core/entities/enemy.h"

galaga::Enemy::Enemy(const glm::vec2& position) : center_position_(position) {
  is_dead_ = false;
  explosion_timer_ = 40;

  // Sets the sprite to a random image from the three available
  ci::Rand::randomize();
  size_t sprite_num = cinder::randInt(3);
  switch (sprite_num) {
    case 0:
      texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteOneFilePath));
      break;
    case 1:
      texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteTwoFilePath));
      break;
    case 2:
      texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteThreeFilePath));
      break;
  }
}

void galaga::Enemy::Update() {
  center_position_[1] += kSpeed;
}

void galaga::Enemy::Draw() const {
  ci::gl::draw(texture_, GenerateRectPosition());
}

void galaga::Enemy::Destroy() {
  is_dead_ = true;
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kExplosionFilePath));
}

galaga::Enemy& galaga::Enemy::Enemy::operator=(const Enemy& source) {
  this->center_position_ = source.center_position_;
  this->is_dead_ = source.is_dead_;
  this->texture_ = source.texture_;
  this->explosion_timer_ = source.explosion_timer_;
  return *this;
}


cinder::Rectf galaga::Enemy::GenerateRectPosition() const {
  // Rectangle made with four corners of sprite
  cinder::Rectf drawRect(center_position_[0] - kEnemyDimensions / 2,
                         center_position_[1] - kEnemyDimensions / 2,
                         center_position_[0] + kEnemyDimensions / 2,
                         center_position_[1] + kEnemyDimensions / 2);

  return drawRect;
}

void galaga::Enemy::DecrementExplosionTimer() {
  explosion_timer_--;
}

size_t galaga::Enemy::GetExplosionTimer() const {
  return explosion_timer_;
}

bool galaga::Enemy::IsDead() const {
  return is_dead_;
}

