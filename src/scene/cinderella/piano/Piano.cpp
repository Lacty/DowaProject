
#include "Piano.hpp"

#include "../../../resource/ResourceManager.hpp"

Piano::Piano(const ci::Vec3f& mPianoPos, const ci::Vec3f& mPianoSize)
{
  mIsPlay = false;
  mVolume = 0.0f;
  mFadeSpeed = 0.05f;
  
  mPos = mPianoPos;
  mSize = mPianoSize;
  
  setColliderType(Collider::Rect);
}

void Piano::setup(){}

void Piano::update() {}

void Piano::draw()
{
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  mPiano.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mPiano.unbind();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
}

void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball")
  {
    mIsPlay = true;
  }
}
