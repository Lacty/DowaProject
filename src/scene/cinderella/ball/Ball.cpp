
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
    
    // ここの部分を変えれば座標系が変わっても動く
    // たぶんカメラをつけたら座標系がずれるので
    // yを逆にすれば動くとおもわれ
    // もしx方向に傾けたのにy方向に動くとしたら
     mPos.x -= mAcc.y;
     mPos.y -= mAcc.x;
    // そこからさらにxのプラス方向に傾けたのにマイナス方向に移動した場合は
    // mPos.x -= としてあげれば動くとおもわれ
//    mPos.x += mAcc.x;
//    mPos.y += mAcc.y;
  }
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

void Ball::setStageLeft(float left) {
  mStageLeft = left;
}

bool Ball::isOutOfStage() {
  return mPos.x < mStageLeft;
}
