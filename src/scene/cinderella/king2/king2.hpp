
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class King2 : public Object
{
  
  ci::gl::Texture mKing2;
  
  void drawKing2(const ci::gl::Texture&);
  
public:
  
  King2(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
