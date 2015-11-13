
#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"


class Device {
private:
  bool mIsTouchBegan;
  ci::Vec2f mTouchPos;
  
  static Device& get();
  
  Device() = default;
  
public:
  static void enable();
  static const bool isDataAvailable();
  
  static const ci::Quatf getRotation();
  static const ci::Vec3f getRotationRate();
  
  static void setTouchState(bool touch, const ci::Vec2f& pos);
  static const bool isTouchBegan();
  static const ci::Vec2f getTouchPos();
};
