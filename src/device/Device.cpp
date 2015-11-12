
#include "Device.hpp"


Device& Device::get() {
  static Device instance;
  return instance;
}


//-----------------------------------------------//
#if !defined(CINDER_MSW)

#include "cinder/MotionManager.h"

void Device::enable() {
  get();
  //ci::MotionManager::enable();
}

bool Device::isDataAvailable() {
  return ci::MotionManager::isDataAvailable();
}

ci::Quatf Device::getRotation() {
  return ci::MotionManager::getRotation();
}

ci::Vec3f Device::getRotationRate() {
  return ci::MotionManager::getRotationRate();
}

void Device::setTouchState(bool isTouch, const ci::Vec2f& pos) {
  get().mIsTouchBegan = isTouch;
  get().mTouchPos = pos;
}

bool Device::isTouchBegan() {
  return get().mIsTouchBegan;
}

ci::Vec2f Device::getTouchPos() {
  return get().mTouchPos;
}

//-----------------------------------------------//
#else // if (CINDER_MSW)

void Device::enable() {
  get();
}

bool Device::isDataAvailable() {
  return true;
}

ci::Quatf Device::getRotation() {
  return ci::Quatf(0, 0, 0, 0);
}

ci::Vec3f Device::getRotationRate() {
  return ci::Vec3f::zero();
}

void Device::setTouchState(bool isTouch, const ci::Vec2f& pos) {
  get().mIsTouchBegan = isTouch;
  get().mTouchPos = pos;
}

bool Device::isTouchBegan() {
  return get().mIsTouchBegan;
}

ci::Vec2f Device::getTouchPos() {
  return get().mTouchPos;
}

#endif