
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class GateSide : public Object
{
  ci::gl::Texture mGateSide;
  
public:
  
  GateSide(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
