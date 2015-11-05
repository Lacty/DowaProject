
#pragma once
#include "SceneMaker.hpp"
#include "Scene.hpp"
#include <memory>


class Scene;
enum class SceneType;

class SceneManager {
private:
  SceneType mType;
  SceneMaker mMaker;
  std::unique_ptr<Scene> mScene;
  
  static SceneManager& get();
  
  SceneManager() = default;
  
public:
  
  static void create(const SceneType& type);
  static SceneType getSceneType();
  
  static void update();
  static void draw();
};
