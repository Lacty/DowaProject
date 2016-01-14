
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Chandelier : public Object
{
  ci::gl::Texture mChandelier;
  
public:
  
  Chandelier(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
