
#pragma once

#include "../../../object/Object.hpp"
#include "../../../resource/Resource.hpp"

#include "cinder/gl/Texture.h"

class Plate : public Object
{
  ci::gl::Texture mPlate;
  ci::gl::Texture mPlateFall;
  
  bool mFallFlag;
  
  bool mTextureChangeFlag;
  
  void drawPlate();
  void drawPlateFall();
  
  Audio mPlateFallSE;
  bool mSePlayFlag;
  
public:
  
  Plate(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);
};
