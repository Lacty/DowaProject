
#include "Scene.hpp"
#include "SceneManager.hpp"


void Scene::setNextScene(const SceneType& scene, const FadeType& fadeIn, const FadeType& fadeOut) {
  SceneManager::setNextScene(scene, fadeIn, fadeOut);
}

const SceneType Scene::getSceneType() const {
  return SceneManager::getSceneType();
}