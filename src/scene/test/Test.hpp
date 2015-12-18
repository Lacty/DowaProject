
#pragma once
#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"


class Test : public Scene {
private:
  dowa::hidden::Audio se;
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
