
#include "Test.hpp"
#include "../../window/Window.hpp"
#include "../../object/Task.hpp"

#include "Player.hpp"
#include "Enemy.hpp"

#include "Cinderella.hpp"
#include "Floor.hpp"

#include "../SceneManager.hpp"
#include "../../device/Device.hpp"

Test::Test() {}

void Test::update() {
  if (dowa::Device::isTouchBegan()) {
    std::cout << "aa" << std::endl;
    SceneManager::create(SceneType::Cinderella);
  }
}

void Test::draw() {}
