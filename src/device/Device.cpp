
#include "Device.hpp"


Device& Device::get() {
  static Device instance;
  return instance;
}

bool Device::mIsTouchBegan = false;
ci::Vec2f Device::mTouchPos = ci::Vec2f::zero();


//-----------------------------------------------//
#if !defined(CINDER_MSW)

#include "cinder/MotionManager.h"

void Device::enable() {
  get();
  mIsTouchBegan = false;
  mTouchPos = ci::Vec2f::zero();
  ci::MotionManager::enable();
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
  mIsTouchBegan = isTouch;
  mTouchPos = pos;
}

bool Device::isTouchBegan() {
  return mIsTouchBegan;
}

ci::Vec2f Device::getTouchPos() {
  return mTouchPos;
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
  mIsTouchBegan = isTouch;
  mTouchPos = pos;
}

bool Device::isTouchBegan() {
  return mIsTouchBegan;
}

ci::Vec2f Device::getTouchPos() {
  return mTouchPos;
}

#endif