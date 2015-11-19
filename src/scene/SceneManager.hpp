
#pragma once
#include <memory>

#include "SceneMaker.hpp"
#include "Scene.hpp"

#include "fade/FadeBase.h"
#include "fade/FadeIn.h"
#include "fade/FadeOut.h"



class SceneManager {
private:
  SceneType mCurrentType;
  SceneType mNextType;
  SceneMaker mMaker;
  std::unique_ptr<Scene> mScene;
  
  FadeIn mFadeIn;
  FadeOut mFadeOut;
  
  static SceneManager& get();
  
  SceneManager();
  
public:
  
  static void create(const SceneType& scene);
  
  static void setNextScene(const SceneType& scene, const FadeType& fade);
  static SceneType getSceneType();
  
  static void update();
  static void draw();
};
