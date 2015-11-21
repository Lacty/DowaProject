
#pragma once
#include <memory>

#include "SceneMaker.hpp"
#include "Scene.hpp"

#include "fade/FadeBase.hpp"
#include "fade/FadeIn.hpp"
#include "fade/FadeOut.hpp"



class SceneManager {
private:
  SceneType mCurrentType;
  SceneType mNextType;
  SceneMaker mMaker;
  std::unique_ptr<Scene> mScene;
  
  FadeIn mFadeIn;
  FadeOut mFadeOut;
  
  static SceneManager& get();
  
   bool isDuringFade();
  
  SceneManager();
  
public:
  
  static void create(const SceneType& scene);
  
  static void setNextScene(const SceneType& scene, const FadeType& fadeIn, const FadeType& fadeOut);
  static SceneType getSceneType();
  
  static void update();
  static void draw();
};
