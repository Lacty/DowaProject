
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Sister : public Object
{
  
  ci::gl::Texture mSister1;
  ci::gl::Texture mSister2;
  
  void drawSister(const ci::gl::Texture&);
  
public:
  
  Sister(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
