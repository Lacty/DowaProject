
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Plate : public Object
{
  ci::gl::Texture mPlate;
  ci::gl::Texture mPlateFall;
  
public:
  
  Plate(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
