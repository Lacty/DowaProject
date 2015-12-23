
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Townwindow : public Object
{
  ci::gl::Texture mTownWindowTop; // Top
  ci::gl::Texture mTownWindowLeft; // Left
  ci::gl::Texture mTownWindowRight; // Right
  ci::gl::Texture mTownWindowOpen; // Boy
  
  std::string mTownwindowName;
  
  void drawTownwindow(const ci::gl::Texture&);
  
public:
  
  Townwindow(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
};
