
#pragma once
#include "../Scene.hpp"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


class Test : public Scene {
private:
  ci::gl::Texture image;
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
