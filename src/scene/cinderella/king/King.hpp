
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class King : public Object
{
  
  ci::gl::Texture mKing1;
  ci::gl::Texture mKing2;
  
  void drawKing(const ci::gl::Texture&);
  
public:
  
  King(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
