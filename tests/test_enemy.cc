#include <core/entities/enemy.h>

#include <catch2/catch.hpp>

using namespace::galaga;

TEST_CASE("Generate Enemy hitbox") {
  Enemy enemy(glm::vec2(100, 100));

  REQUIRE(enemy.GenerateRectPosition().getUpperLeft() == glm::vec2(80, 80));
  REQUIRE(enemy.GenerateRectPosition().getLowerRight() == glm::vec2(120, 120));
}

TEST_CASE("Update Enemy position") {
  Enemy enemy(glm::vec2(100, 100));

  enemy.Update();
  REQUIRE(enemy.GenerateRectPosition().getCenter() == glm::vec2(100, 100.5));
}

TEST_CASE("Destroy Enemy") {
  Enemy enemy(glm::vec2(100, 100));

  enemy.Destroy();
  REQUIRE(enemy.IsDead());
}

TEST_CASE("Decrement Enemy explosion timer") {
  Enemy enemy(glm::vec2(100, 100));

  enemy.Destroy();
  size_t initial_timer = enemy.GetExplosionTimer();
  enemy.DecrementExplosionTimer();
  REQUIRE(enemy.GetExplosionTimer() == (initial_timer-1));
}

TEST_CASE("Enemy copy assignment operator") {
  Enemy enemy1(glm::vec2(100, 100));
  Enemy enemy2(glm::vec2(200, 200));
  enemy1 = enemy2;

  REQUIRE(enemy1.GenerateRectPosition().getCenter() == glm::vec2(200, 200));
  REQUIRE(enemy2.GenerateRectPosition().getCenter() == glm::vec2(200, 200));
}