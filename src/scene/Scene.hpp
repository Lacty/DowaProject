
#pragma once


enum class FadeType;

enum class SceneType {
  Title,
  Select,
  GameMain,
  Result,
  
  Test
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
