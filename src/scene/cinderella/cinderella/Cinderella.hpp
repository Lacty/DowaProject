
# pragma once

#include "cinder/gl/Texture.h"

#include "../../../object/Object.hpp"

class Cinderella : public Object
{
  int mCount; // アニメーション
  float mGravityPower; // 重力パワー
  float mAcceleration; // 加速度
  
  bool mSetFlag, mBookHitFlag, mRiverHitFlag;
  
  bool mStairs2Hit;
  
  bool mDanceSetFlag, mDanceFlag;
  
  bool mDressFlag;
  
  bool mOut1, mOut2;
  
  ci::Vec3f mOffSet;
  
  std::string mFloorStr;

  ci::gl::Texture mCinderellaStatic;
  ci::gl::Texture mCinderellaLeft;
  ci::gl::Texture mCinderellaRight;
  ci::gl::Texture mCinderellaBookHit;
  ci::gl::Texture mCinderellaSubmerge;
  ci::gl::Texture mCinderellaDance;
  ci::gl::Texture mCinderellaDress1;
  ci::gl::Texture mCinderellaDress2;
  
  ci::gl::Texture mCinderellaOut1;
  ci::gl::Texture mCinderellaOut2;
  ci::gl::Texture mCinderellaOut3;
  ci::gl::Texture mCinderellaOut4;
  
  void drawCinderella(const ci::gl::Texture&, const ci::Vec3f&);
  
  void bookHitSet();
  void danceSet();
  void drawDance();
  
public:
  
  Cinderella(const ci::Vec3f&, const ci::Vec3f&);
  
  bool mGameOverRturen;
  float mGameOverOffset;
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
  
};
