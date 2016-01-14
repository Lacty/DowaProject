
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Hydrant : public Object
{
  ci::gl::Texture mHydrant;
  
public:
  
  Hydrant(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
