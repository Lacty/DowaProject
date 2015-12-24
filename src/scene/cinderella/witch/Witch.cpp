
#include "Witch.hpp"

#include "../../../resource/Resource.hpp"


Witch::Witch(const ci::Vec3f& WitchPos, const ci::Vec3f& WitchSize)
{
  mPos = WitchPos;
  mSize = WitchSize;
  
  mWitch = TextureManager::find(ResKey::CApple);
  
}

void Witch::setup() {}

void Witch::update() {}

void Witch::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mWitch.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mWitch.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
