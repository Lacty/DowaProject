
# pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Shoes : public Object
{
  ci::gl::Texture mShoes;
  
  void drawShoes(const ci::gl::Texture&);
  
public:
  
  Shoes(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
