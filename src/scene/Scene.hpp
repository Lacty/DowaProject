
#pragma once


enum class SceneType {
  Title,
  Select,
  GameMain,
  Result,
  
  Test
};

enum class FadeType {
  None,
  
  FullScreen,
  Circle,
  Vell,
  FromLeft,
  FromRight,
  BothSide,
  Hole
};

class Scene {
public:
  Scene() = default;
  virtual ~Scene() {};
  
  virtual void update() = 0;
  virtual void draw() = 0;
  
  void setNextScene(const SceneType& scene, const FadeType& fade);
  const SceneType getSceneType() const;
};
