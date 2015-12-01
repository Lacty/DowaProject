
#include "Test.hpp"
#include "../../window/Window.hpp"
#include "../../device/Device.hpp"

#include "../../object/Task.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

#include "../SceneManager.hpp"

#include "../../resource/ResourceManager.hpp"

Test::Test() {
  Task::add("Player", std::make_shared<Player>());
  Task::add("Enemy", std::make_shared<Enemy>());

  cam = dowa::Camera(60.f, 0.5f, 300.f);
  cam.lookAt(ci::Vec3f(0, 0, 300), ci::Vec3f(0, 0, 0), ci::Vec3f::yAxis());
  cam.setDistMinMax(100, 300);
  cam.setForcusObject(Task::find("Player"), Task::find("Enemy"));
  cam.setForcusNum(dowa::Camera::Forcus::One);
}

void Test::update() {
  cam.setMatrices();
  cam.forcus();

  if (!dowa::ResourceManager::audio().get(AudioKey::Menu).bgm->isEnabled()){
    dowa::ResourceManager::audio().get(AudioKey::Menu).bgm->enable();
    dowa::ResourceManager::audio().get(AudioKey::Menu).gain->setValue(1.0f);
  }

  if (!dowa::Device::isTouchBegan()) return;
  Task::clear();
  SceneManager::create(SceneType::Title);
}

void Test::draw() {}
