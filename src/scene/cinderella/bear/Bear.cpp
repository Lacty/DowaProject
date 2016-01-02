
#include "Bear.hpp"

#include "../../../resource/Resource.hpp"


Bear::Bear(const ci::Vec3f& mBearPos, const ci::Vec3f& mBearSize, const std::string& mBearNamef)
{
  mPos = mBearPos;
  mSize = mBearSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mBearName = mBearNamef;
  
  mHungryBear = TextureManager::find(ResKey::CHungryBear);
  mSatisfiedBear = TextureManager::find(ResKey::CStatisfiedBrear);
  
  setColliderType(Collider::Rect);
}

void Bear::setup() {}

void Bear::update() {}

void Bear::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  if(mBearName == "HungryBear") drawBear(mHungryBear);
  if(mBearName == "SatisfiedBear") drawBear(mSatisfiedBear);
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  
  ci::gl::disable(GL_CULL_FACE);
}

void Bear::drawBear(ci::gl::Texture& mBearTexture)
{
  mBearTexture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBearTexture.unbind();
}

void Bear::onCollisionUpdate(const std::shared_ptr<Object> &compare)
{
  std::string name;
  name = compare -> getName();
  name.resize(5);
  
  if(name == "Apple")
  {
    mBearName = "SatisfiedBear";
    
    compare -> setState(State::Dead);
  }
}
