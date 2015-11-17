
#include "Scene.hpp"
#include "SceneManager.hpp"


void Scene::setNextScene(const SceneType& type) {
  SceneManager::create(type);
}

const SceneType Scene::getSceneType() const {
  return SceneManager::getSceneType();
}