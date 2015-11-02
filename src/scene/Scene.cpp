
#include "Scene.hpp"


void Scene::setNextScene(const SceneType& type) {
  this->type = type;
}

SceneType Scene::getSceneType() {
  return type;
}