
# pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class HandRail : public Object
{
  ci::gl::Texture mHandRail;
  
public:
  
  HandRail(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
