#include <core/particles/player_bullet.h>

#include <catch2/catch.hpp>

using namespace::galaga;

TEST_CASE("Generate Bullet hitbox") {
  PlayerBullet player_bullet(glm::vec2(100, 100));

  REQUIRE(player_bullet.GenerateRectPosition().getUpperLeft() == glm::vec2(95, 95));
  REQUIRE(player_bullet.GenerateRectPosition().getLowerRight() == glm::vec2(105, 105));
}

TEST_CASE("Update Bullet position") {
  PlayerBullet player_bullet(glm::vec2(100, 100));

  player_bullet.Update();
  REQUIRE(player_bullet.GenerateRectPosition().getCenter() == glm::vec2(100, 110));
}

TEST_CASE("Bullet copy assignment operator") {
  PlayerBullet player_bullet1(glm::vec2(100, 100));
  PlayerBullet player_bullet2(glm::vec2(200, 200));
  player_bullet1 = player_bullet2;

  REQUIRE(player_bullet1.GenerateRectPosition().getCenter() == glm::vec2(200, 200));
  REQUIRE(player_bullet2.GenerateRectPosition().getCenter() == glm::vec2(200, 200));
}