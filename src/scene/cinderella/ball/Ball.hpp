
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"


class Ball : public Object {
private:
  ci::Vec3f mAcc;
  ci::Vec3f mRot;
  ci::Quatf mQua;
  float mSpeedRate;
  
  float mStageLeft;
  
  ci::gl::Texture mSphereBlue;
  
public:
  
  // speedRateは大きいほど玉が早く移動する
  // 使用した感じ"0.1" "0.2"あたりがいいかと思われ
  Ball(const ci::Vec3f& pos, const ci::Vec3f& size, float speedRate = 0.2f);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
  
  void setStageLeft(float left);
  bool isOutOfStage();
};
