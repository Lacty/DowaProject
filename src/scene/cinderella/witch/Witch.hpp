
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Witch : public Object
{
  ci::gl::Texture mWitch;
  
public:
  
  Witch(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
