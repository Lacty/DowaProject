
#include "Test.hpp"
#include "../../object/Task.hpp"
#include "../../device/Device.hpp"
#include "../SceneManager.hpp"

#include "ball/Ball.hpp"


Test::Test() {
<<<<<<< HEAD
  cam = dowa::Camera();
  Task::add("Ball", std::make_shared<Ball>(ci::Vec3f::zero(), ci::Vec3f(50, 50, 5)));
=======
  //Task::add("Ball", std::make_shared<Ball>(ci::Vec3f::zero(), ci::Vec3f(50, 50, 5)));
>>>>>>> 8579e526e589da71a57d9ccd33f8b61f290744b8
}

Test::~Test() {
  ci::gl::popMatrices();
  std::cout << "a\n";
}

void Test::update() {
  if (dowa::Device::isTouchBegan()) {
    Task::clear();
    SceneManager::create(SceneType::Test);
  }
}

void Test::draw() {}
