
#include "Scene.hpp"
#include "SceneManager.hpp"


void Scene::setNextScene(const SceneType& scene, const FadeType& fadeIn) {
  SceneManager::setNextScene(scene, fadeIn);
}

void Scene::setFadeOut(const FadeType &fadeOut) {
  SceneManager::setFadeOut(fadeOut);
}

const SceneType Scene::getSceneType() const {
  return SceneManager::getSceneType();
}
