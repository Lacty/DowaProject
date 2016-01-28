
#include "Apple.hpp"

#include "../../../resource/Resource.hpp"


Apple::Apple(const ci::Vec3f& mApplePos, const ci::Vec3f& mAppleSize)
{
  mPos = mApplePos;
  mSize = mAppleSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mFallFlag = false;
  mFloorHitFlag = false;
  mAcceleration = 0.f;
  mGravityPower = 0.2f;
  
  mApple = TextureManager::find(ResKey::CApple);
  
  setColliderType(Collider::Rect);
  
}

void Apple::setup() {}

void Apple::update()
{
  if(mFallFlag && mFloorHitFlag == false)
  {
    mAcceleration += mGravityPower;
    mPos.y -= mAcceleration;
  }
}

void Apple::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mApple.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mApple.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Apple::onCollisionUpdate(const std::shared_ptr<Object> &compare)
{
  if(compare -> getName() == "Ball")
  {
    mFallFlag = true;
  }
  
  if(compare -> getName() == "Floor_Floor" || compare -> getName() == "Floor_Floor2")
  {
    mFloorHitFlag = true;
    mRotate.z += 0.25f;
    mPos.x += 0.05f;
  }
}
