
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Pumpkin : public Object
{
  ci::gl::Texture mPumpkin1;
  ci::gl::Texture mPumpkin2;
  
  std::string mPumpkinName;
  
  void drawPumpkin(const ci::gl::Texture&);
  
public:
  
  Pumpkin(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
};
