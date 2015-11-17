
#include "SceneManager.hpp"
#include "Scene.hpp"
#include "../object/Task.hpp"


SceneManager::SceneManager() :
isDuringFade(false) {}

SceneManager& SceneManager::get() {
  static SceneManager instance;
  return instance;
}


void SceneManager::create(const SceneType &scene) {
  get().mScene = get().mMaker.create(scene);
}

void SceneManager::setNextScene(const SceneType& scene, const FadeType& fade) {
  get().mFadeIn = fade;
  get().mSceneType = scene;
}

SceneType SceneManager::getSceneType() {
  return get().mSceneType;
}

void SceneManager::update() {
  get().mScene->update();
  Task::update();
}

void SceneManager::draw() {
  get().mScene->draw();
  Task::draw();
}