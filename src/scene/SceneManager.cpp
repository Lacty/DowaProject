
#include "SceneManager.hpp"
#include "Scene.hpp"
#include "../object/Task.hpp"


SceneManager::SceneManager() {}

SceneManager& SceneManager::get() {
  static SceneManager instance;
  return instance;
}


bool SceneManager::isDuringFade() {
  return get().mCurrentType != get().mNextType;
}

void SceneManager::create(const SceneType &scene) {
  get().mCurrentType = scene;
  get().mScene = get().mMaker.create(scene);
}

void SceneManager::setNextScene(const SceneType& scene, const FadeType& fadeIn, const FadeType& fadeOut) {
  get().mNextType = scene;
  get().mFadeIn.setType(fadeIn);
  get().mFadeOut.setType(fadeOut);
}

SceneType SceneManager::getSceneType() {
  return get().mCurrentType;
}

void SceneManager::update() {
  get().mScene->update();
  Task::update();
  
  if (!get().isDuringFade()) return;
  if (!get().mFadeIn.getIsEnd()) return;
  get().create(get().mNextType);
}

void SceneManager::draw() {
  get().mScene->draw();
  Task::draw();
  get().mFadeIn.draw();
  get().mFadeOut.draw();
}