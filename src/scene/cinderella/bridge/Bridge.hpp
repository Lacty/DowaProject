
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Bridge : public Object
{
  ci::gl::Texture mBridge;
  
public:
  
  Bridge(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
