
#pragma once


enum class SceneType {
  Title,
  Select,
  GameMain,
  Result
};

class Scene {
public:
  Scene() = default;
  virtual ~Scene() {};
  
  virtual void update() = 0;
  virtual void draw() = 0;
  
  void setNextScene(const SceneType& type);
  SceneType getSceneType();
};
