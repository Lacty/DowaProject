
#pragma once


enum class SceneType {
  Title,
  Main,
  Result
};

class Scene {
protected:
  SceneType type;
  
public:
  Scene() = default;
  virtual ~Scene();
  
  virtual void update() = 0;
  virtual void draw() = 0;
  
  void setSceneType(const SceneType& type);
};
