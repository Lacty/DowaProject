
#include "Bear.hpp"

#include "../../../resource/Resource.hpp"


Bear::Bear(const ci::Vec3f& mBearPos, const ci::Vec3f& mBearSize)
{
  mPos = mBearPos;
  mSize = mBearSize;
  
  mHungryBear = TextureManager::find(ResKey::CHungryBear);
  mSatisfiedBear = TextureManager::find(ResKey::CStatisfiedBrear);
}

void Bear::setup() {}

void Bear::update() {}

void Bear::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  mHungryBear.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mHungryBear.unbind();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  
  ci::gl::disable(GL_CULL_FACE);
}
