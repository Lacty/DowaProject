
#pragma once
#include "../Scene.hpp"
#include "camera/Camera.hpp"


class Test : public Scene {
private:
  dowa::Camera cam;
  
public:
  Test();
  
  void update();
  void draw();
};
