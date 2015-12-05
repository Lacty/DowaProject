
#pragma once


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

enum class SceneType {
  Title,
  Select,
  GameMain,
  Result,
  
  Test,
  Loading
};

class Scene {
public:
  Scene() = default;
  virtual ~Scene() {};
  
  virtual void update() = 0;
  virtual void draw() = 0;
  
  void setNextScene(const SceneType& scene, const FadeType& fadeIn);
  void setFadeOut(const FadeType& fadeOut);
  const SceneType getSceneType() const;
};
