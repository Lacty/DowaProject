
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Horse : public Object
{
  
  ci::gl::Texture mHorse1;
  ci::gl::Texture mHorse2;
  ci::gl::Texture mHorse3;
  ci::gl::Texture mHorse4;
  ci::gl::Texture mHorse5;
  ci::gl::Texture mHorse6;
  
  int mCount;
  
  float mGravityPower, mAcceleration;
  
  void drawHorse(ci::gl::Texture&);
  
public:
  
  Horse(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
};
