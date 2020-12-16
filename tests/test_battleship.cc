#include <core/entities/battleship.h>

#include <catch2/catch.hpp>

using namespace::galaga;

TEST_CASE("Generate Battleship hitbox") {
  Battleship battleship(glm::vec2(100, 100));

  REQUIRE(battleship.GenerateRectPosition().getUpperLeft() == glm::vec2(80, 80));
  REQUIRE(battleship.GenerateRectPosition().getLowerRight() == glm::vec2(120, 120));
}

TEST_CASE("Battleship move") {
  Battleship battleship(glm::vec2(100, 100));

  SECTION("Right") {
    battleship.MoveRight();
    REQUIRE(battleship.GenerateRectPosition().getCenter() == glm::vec2(108, 100.5));
  }

  SECTION("Left") {
    battleship.MoveLeft();
    REQUIRE(battleship.GenerateRectPosition().getCenter() == glm::vec2(92, 100.5));
  }
}

TEST_CASE("Battleship destroy") {
  Battleship battleship(glm::vec2(100, 100));

  battleship.Destroy();
  REQUIRE(battleship.IsDead());
}

TEST_CASE("Decrement Battleship explosion timer") {
  Battleship battleship(glm::vec2(100, 100));

  battleship.Destroy();
  size_t initial_timer = battleship.GetExplosionTimer();
  battleship.DecrementExplosionTimer();
  REQUIRE(battleship.GetExplosionTimer() == (initial_timer-1));
}