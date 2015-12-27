
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class TownwindowHit : public Object
{
  ci::gl::Texture mTownWindowTop; // Top
  ci::gl::Texture mTownWindowLeft; // Left
  ci::gl::Texture mTownWindowRight; // Right
  ci::gl::Texture mTownWindowOpen; // Boy
  
  std::string mTownwindowName;
  
  void drawTownwindow(const ci::gl::Texture&);
  
public:
  
  TownwindowHit(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);
  
};
