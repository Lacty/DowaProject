
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"


class Bear : public Object
{
  ci::gl::Texture mHungryBear;
  ci::gl::Texture mSatisfiedBear;
  
public:
  
  Bear(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
