
#include "SceneManager.hpp"
#include "Scene.hpp"
#include "../object/Task.hpp"
#include "../resource/Resource.hpp"


SceneManager::SceneManager() {}

SceneManager& SceneManager::get() {
  static SceneManager instance;
  return instance;
}

bool SceneManager::isDuringFade() {
  return get().mCurrentType != get().mNextType;
}

void SceneManager::enable() {
  get();
}

void SceneManager::create(const SceneType &scene) {
  get().mCurrentType = scene;
  get().mScene = get().mMaker.create(scene);
}

void SceneManager::setNextScene(const SceneType& scene, const FadeType& fadeIn) {
  get().mNextType = scene;
  get().mFadeIn.setType(fadeIn);
}

void SceneManager::setFadeOut(const FadeType &fadeOut) {
  get().mFadeOut.setType(fadeOut);
}

SceneType SceneManager::getSceneType() {
  return get().mCurrentType;
}

void SceneManager::update() {
  get().mScene->update();
  Task::update();
  
  AudioManager::update();
  
  get().mFadeIn.update();
  get().mFadeOut.update();
  
  if (get().mCurrentType == get().mNextType) return;
  if (!get().mFadeIn.getIsEnd()) return;
  get().create(get().mNextType);
}

void SceneManager::draw() {
  Task::draw();
  get().mScene->draw();
  
  get().mFadeIn.draw();
  get().mFadeOut.draw();
}