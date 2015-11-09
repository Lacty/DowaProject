
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
  static bool isDataAvailable();
  
  static ci::Quatf getRotation();
  static ci::Vec3f getRotationRate();
  
  static void setTouchState(bool touch, const ci::Vec2f& pos);
  static bool isTouchBegan();
  static ci::Vec2f getTouchPos();
};
