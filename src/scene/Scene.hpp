
#pragma once


enum class SceneType {
  Title,
  GameMain,
  Result
};

class Scene {
protected:
  SceneType type;
  
public:
  Scene() = default;
  virtual ~Scene() {};
  
  virtual void update() = 0;
  virtual void draw() = 0;
  
  void setNextScene(const SceneType& type);
  SceneType getSceneType();
};
