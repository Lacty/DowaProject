
#pragma once
#include "../Scene.hpp"
#include "../cinderella/camera/Camera.hpp"


class Test : public Scene {
private:
  dowa::Camera cam;
  
public:
  Test();
  
  ~Test();
  
  void update();
  void draw();
};
