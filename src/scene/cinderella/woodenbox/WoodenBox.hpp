
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class WoodenBox : public Object
{
  ci::gl::Texture mWoodenBox;
  
public:
  
  WoodenBox(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
