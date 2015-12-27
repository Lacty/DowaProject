
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class River : public Object
{
  ci::gl::Texture mRiver;
  
public:
  
  River(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
