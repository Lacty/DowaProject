
#pragma once
#include "../Scene.hpp"
#include "../../object/Object.hpp"

class Test : public Scene {
private:
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
