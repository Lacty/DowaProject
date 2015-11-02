
#include "Scene.hpp"
#include "SceneManager.hpp"


void Scene::setNextScene(const SceneType& type) {
  SceneManager::create(type);
}

SceneType Scene::getSceneType() {
  return SceneManager::getSceneType();
}