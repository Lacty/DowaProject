
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Shop : public Object
{
  ci::gl::Texture mShop;
  
public:
  
  Shop(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
