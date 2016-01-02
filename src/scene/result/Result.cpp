
#include "Result.hpp"
#include "../SceneManager.hpp"
#include "../../device/Device.hpp"


Result::Result() {
  std::cout << "start result" << std::endl;
}

Result::~Result() {
  std::cout << "end result" << std::endl;
}

void Result::update() {
  if (dowa::Device::isTouchBegan()) {
    SceneManager::create(SceneType::Test);
  }
}

void Result::draw() {}
