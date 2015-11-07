
#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"


class Device {
private:
  
  static Device& get();
  
  Device() = default;
  
public:
  
  static void enable();
  static void disable();
  
  static ci::Vec2f getTouchPos();
  static bool isTouchBegin();
};
