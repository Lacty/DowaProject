
#include "Device.hpp"


using namespace dowa;

Device& Device::get() {
  static Device instance;
  return instance;
}

//-----------------------------------------------//
#if !defined(CINDER_MSW)

#include "cinder/MotionManager.h"

void Device::enable() {
  get();
  ci::MotionManager::enable();
}

const bool Device::isDataAvailable() {
  return ci::MotionManager::isDataAvailable();
}

const ci::Quatf Device::getRotation() {
  return ci::MotionManager::getRotation();
}

const ci::Vec3f Device::getRotationRate() {
  return ci::MotionManager::getRotationRate();
}

void Device::setTouchState(bool isTouch, const ci::Vec2f& pos) {
  get().mIsTouchBegan = isTouch;
  get().mTouchPos = pos;
}

const bool Device::isTouchBegan() {
  return get().mIsTouchBegan;
}

const ci::Vec2f Device::getTouchPos() {
  return get().mTouchPos;
}

//-----------------------------------------------//
#else // if (CINDER_MSW)

void Device::enable() {
  get();
}

const bool Device::isDataAvailable() {
  return true;
}

const ci::Quatf Device::getRotation() {
  return ci::Quatf(0, 0, 0, 0);
}

const ci::Vec3f Device::getRotationRate() {
  return ci::Vec3f::zero();
}

void Device::setTouchState(bool isTouch, const ci::Vec2f& pos) {
  get().mIsTouchBegan = isTouch;
  get().mTouchPos = pos;
}

const bool Device::isTouchBegan() {
  return get().mIsTouchBegan;
}

const ci::Vec2f Device::getTouchPos() {
  return get().mTouchPos;
}

#endif