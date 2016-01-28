
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class GrayCube : public Object
{
  ci::gl::Texture mGrayCube;
  
public:
  
  GrayCube(const ci::Vec3i&, const ci::Vec3i&);
  
  void setup();
  void update();
  void draw();
  
};
