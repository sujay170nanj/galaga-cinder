//
// Created by sujay on 11/17/2020.
//

#include "visualizer/space.h"

galaga::Space::Space(const glm::vec2& top_left_corner, size_t dimensions,
                     const std::vector<Hitbox>& hitboxes)
    : top_left_corner_(top_left_corner),
      dimensions_(dimensions),
      hitboxes_(hitboxes),
      battleship_(glm::vec2(
          top_left_corner_[0] + static_cast<float>(dimensions) / 2,
          top_left_corner_[1] + 9 * static_cast<float>(dimensions) / 10)) {
}

void galaga::Space::Update() {
  for (PlayerBullet& bullet: bullets_) {
    bullet.Update();
  }

}

void galaga::Space::Draw() const {
  cinder::gl::Texture2dRef background_texture =
      cinder::gl::Texture2d::create(cinder::loadImage(kBackgroundFilePath));
  ci::gl::draw(background_texture,
               ci::Rectf(top_left_corner_,
                         glm::vec2(top_left_corner_[0] + dimensions_,
                                   top_left_corner_[1] + dimensions_)));

  ci::gl::color(ci::Color::white());
  battleship_.Draw();

  for (const PlayerBullet& bullet: bullets_) {
    bullet.Draw();
  }

}

void galaga::Space::Clear() {

}

void galaga::Space::BattleshipLeftShoot() {
  bullets_.emplace_back(PlayerBullet(glm::vec2(battleship_.GenerateRectPosition().getCenter()[0], battleship_.GenerateRectPosition().getUpperLeft()[1] - kBulletMargin)));
}

galaga::Battleship& galaga::Space::GetBattleship() {
  return battleship_;
}
