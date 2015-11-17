
#pragma once
#include "../Scene.hpp"

class Test : public Scene {
private:
public:
  Test() = default;
  
  void update();
  void draw();
};