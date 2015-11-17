
#include "Scene.hpp"
#include "SceneManager.hpp"


void Scene::setNextScene(const SceneType& scene, const FadeType& fade) {
  SceneManager::setNextScene(scene, fade);
}

const SceneType Scene::getSceneType() const {
  return SceneManager::getSceneType();
}