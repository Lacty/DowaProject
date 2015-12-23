
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class LampPost : public Object
{
  ci::gl::Texture mLampPost;
  
public:
  
  LampPost(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
