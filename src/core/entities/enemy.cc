//
// Created by sujay on 11/17/2020.
//

#include "core/entities/enemy.h"

galaga::Enemy::Enemy(const glm::vec2& position) : center_position_(position) {
  is_dead_ = false;
  explosion_timer_ = 40;
  texture_ = cinder::gl::Texture2d::create(cinder::loadImage(kSpriteFilePath));
}

void galaga::Enemy::Update() {
  center_position_[1] += kVerticalSpeed;
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

