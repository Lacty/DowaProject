
# pragma once

#include "cinder/gl/Texture.h"

#include "../../../object/Object.hpp"

class Cinderella : public Object
{
  int mCount; // アニメーション
  float mGravityPower; // 重力パワー
  float mAcceleration; // 加速度
  
  bool mBookHitFlag;
  bool mSetFlag;
  
  ci::Vec3f mOffSet;
  
  std::string mFloorStr;

  ci::gl::Texture mCinderellaStatic;
  ci::gl::Texture mCinderellaLeft;
  ci::gl::Texture mCinderellaRight;
  ci::gl::Texture mCinderellaBookHit;
  
  void drawCinderella(const ci::gl::Texture&, const ci::Vec3f&);
  
public:
  
  Cinderella(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
  
};
