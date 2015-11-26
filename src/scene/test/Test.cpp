
#include "Test.hpp"

#include "../../object/Task.hpp"
#include "Player.hpp"
#include "Enemy.hpp"


Test::Test() {
  Task::add("Player", std::make_shared<Player>());
  Task::add("Enemy", std::make_shared<Enemy>());
}

void Test::update() {}

void Test::draw() {}