
#include "SceneManager.hpp"
#include "Scene.hpp"


SceneManager& SceneManager::get() {
  static SceneManager instance;
  return instance;
}


void SceneManager::create(const SceneType& type) {
  get().type = type;
  get().scene = get().maker.create(type);
}

SceneType SceneManager::getSceneType() {
  return get().type;
}

void SceneManager::update() {
  get().scene->update();
}

void SceneManager::draw() {
  get().scene->draw();
}