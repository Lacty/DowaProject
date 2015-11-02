
#pragma once
#include "SceneMaker.hpp"
#include "Scene.hpp"
#include <memory>


class Scene;
enum class SceneType;

class SceneManager {
private:
  SceneType type;
  SceneMaker maker;
  std::unique_ptr<Scene> scene;
  
  void create(const SceneType& type);
  
public:
  SceneManager() = default;
  
  // ゲーム開始時に実行されるシーンを指定すること
  SceneManager(const SceneType& type);
  
  void update();
  void draw();
};
