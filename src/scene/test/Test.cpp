
#include "Test.hpp"
#include "../../object/Task.hpp"
#include "../../device/Device.hpp"
#include "../SceneManager.hpp"

#include "ball/Ball.hpp"


Test::Test() {
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f::zero(), ci::Vec3f(50, 50, 5)));
}

void Test::update() {
  if (dowa::Device::isTouchBegan()) {
    Task::clear();
    SceneManager::create(SceneType::Test);
  }
}

void Test::draw() {}
