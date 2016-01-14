
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Witch : public Object
{
  
  bool mTexChange;
  
  ci::gl::Texture mWitch1;
  ci::gl::Texture mWitch2;
  
  void drawWitch(const ci::gl::Texture&);
  
public:
  
  Witch(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
