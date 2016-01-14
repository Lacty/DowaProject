
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"


class Bear : public Object
{
  ci::gl::Texture mHungryBear;
  ci::gl::Texture mSatisfiedBear;
  
  std::string mBearName;
  
  std::string mFloorStr;
  
  void drawBear(ci::gl::Texture&);
  
public:
  
  Bear(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);
  
};
