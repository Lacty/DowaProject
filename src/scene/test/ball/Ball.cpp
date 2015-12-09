
#include "Ball.hpp"
#include "../../../device/Device.hpp"
#include "../../../utility/Utility.hpp"
#include "cinder/Quaternion.h"


Ball::Ball(const ci::Vec3f& pos, const ci::Vec3f& size, float speedRate) :
mAcc(ci::Vec3f::zero()),
mRot(ci::Vec3f::zero()),
speedRate(speedRate)
{
  mPos = pos;
  mSize = size;
  mColor = ci::Color(1, 1, 1);
}


void Ball::setup() {}

void Ball::update() {
  mRot = dowa::Device::getRotationRate();
  
  mRot.y = floor2(mRot.y, 2);
  mRot.x = floor2(mRot.x, 2);
  
  if (dowa::Device::isDataAvailable()) {
    mAcc.x += mRot.y * speedRate;
    mAcc.y += mRot.x * speedRate;
    mPos.x += mAcc.x;
    mPos.y += mAcc.y;
  }
}

void Ball::draw() {
  ci::gl::pushModelView();
  
  ci::gl::color(mColor);
  ci::gl::translate(mPos);
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  
  ci::gl::popModelView();
}