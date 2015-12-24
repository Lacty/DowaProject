
#include "Apple.hpp"

#include "../../../resource/Resource.hpp"


Apple::Apple(const ci::Vec3f& mApplePos, const ci::Vec3f& mAppleSize)
{
  mPos = mApplePos;
  mSize = mAppleSize;
  
  mApple = TextureManager::find(ResKey::CApple);
  
}

void Apple::setup() {}

void Apple::update() {}

void Apple::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mApple.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mApple.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
