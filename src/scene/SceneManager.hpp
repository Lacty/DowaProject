
#pragma once
#include "SceneMaker.hpp"
#include "Scene.hpp"
#include <memory>


class SceneManager {
private:
  SceneType mSceneType;
  FadeType mFadeOut, mFadeIn;
  SceneMaker mMaker;
  std::unique_ptr<Scene> mScene;
  bool isDuringFade;
  
  static SceneManager& get();
  
  SceneManager();
  
  void create(const SceneType& scene);
  
public:
  
  static void setNextScene(const SceneType& scene, const FadeType& fade);
  static SceneType getSceneType();
  
  static void update();
  static void draw();
};
