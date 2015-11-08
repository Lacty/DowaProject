
#pragma once
#include <memory>


class Scene;
enum class SceneType;

class SceneMaker {
public:
  SceneMaker() = default;
  
  std::unique_ptr<Scene> create(const SceneType& type) const;
};