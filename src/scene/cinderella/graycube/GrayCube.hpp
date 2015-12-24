
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class GrayCube : public Object
{
  ci::gl::Texture mGrayCube;
  
public:
  
  GrayCube(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
