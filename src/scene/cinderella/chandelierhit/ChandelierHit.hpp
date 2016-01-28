
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class ChandelierHit : public Object
{
  ci::gl::Texture mChandelierHit;
  
public:
  
  ChandelierHit(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);
  
};
