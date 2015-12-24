
#include "HandRail.hpp"

#include "../../../resource/Resource.hpp"


HandRail::HandRail(const ci::Vec3f& mHandRailPos, const ci::Vec3f& mHandRailSize)
{
  mPos = mHandRailPos;
  mSize = mHandRailSize;
  
  mHandRail = TextureManager::find(ResKey::CHandRail);
  
  setColliderType(Collider::Rect);
}

void HandRail::setup() {}

void HandRail::update() {}

void HandRail::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  mHandRail.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mHandRail.unbind();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  ci::gl::disable(GL_CULL_FACE);
}
