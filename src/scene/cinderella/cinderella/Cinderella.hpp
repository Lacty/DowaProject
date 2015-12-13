
# pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Cinderella : public Object
{
private:
  
  int mCount; // アニメーション
  float mGravityPower; // 重力パワー
  float mAccelerationY; // Yの加速度
  
  std::string mFloorStr;

  ci::gl::Texture mCinderellaStatic;
  ci::gl::Texture mCinderellaLeft;
  ci::gl::Texture mCinderellaRight;
  
public:
  
  Cinderella(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
