
#include "Ball.hpp"

#include "cinder/Quaternion.h"

#include "../../../device/Device.hpp"
#include "../../../utility/Utility.hpp"
#include "../../../resource/Resource.hpp"


Ball::Ball(const ci::Vec3f& pos, const ci::Vec3f& size, float speedRate) :
mAcc(ci::Vec3f::zero()),
mRot(ci::Vec3f::zero()),
mSpeedRate(speedRate)
{
  mPos = pos;
  mSize = size;
  mColor = ci::Color(1.f, 1.f, 1.f);
  
  mSphereBlue = TextureManager::find(ResKey::CSphereBlue);
  
  setColliderType(Collider::Rect);
}

void Ball::setup() {}

void Ball::update()
{
  mRot = dowa::Device::getRotationRate();
  
  mRot.y = floor2(mRot.y, 2);
  mRot.x = floor2(mRot.x, 2);
  
  if (dowa::Device::isDataAvailable())
  {
    mAcc.x += mRot.y * mSpeedRate;
    mAcc.y += mRot.x * mSpeedRate;
    
    mPos.x -= mAcc.y;
    mPos.y -= mAcc.x;
  }
  
  bound();
}

void Ball::draw()
{
  
  ci::gl::pushModelView();
  cinder::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_TEXTURE_2D);
  
  ci::gl::pushModelView();
  mSphereBlue.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  mSphereBlue.unbind();
  ci::gl::popModelView();
  
  ci::gl::disable(GL_TEXTURE_2D);
  
  cinder::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Ball::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() != "Cinderella")
  {
    mPos.x += mAcc.y * 10;
    mPos.y += mAcc.x * 10;
    
    std::cout << compare -> getName() << std::endl;
  }
}


void Ball::bound() {
  // y軸判定
  if (mPos.y + mSize.y * 0.5f > mViewTop) {
    mPos.y = mViewTop - mSize.y * 0.5f;
  }
  if (mPos.y - mSize.y * 0.5f < mViewBottom) {
    mPos.y = mViewBottom + mSize.y * 0.5f;
  }
  // x軸判定
  if (mPos.x + mSize.x * 0.5f > mViewRight) {
    mPos.x = mViewRight - mSize.x * 0.5f;
  }
}

void Ball::setViewSize(float left, float right, float top, float bottom) {
  mViewLeft = left;
  mViewRight = right;
  mViewTop = top;
  mViewBottom = bottom;
}

bool Ball::isOutOfStage() {
  return mPos.x < mViewLeft;
}
