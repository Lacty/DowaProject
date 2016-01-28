
#include "ChandelierHit.hpp"

#include "../../../resource/Resource.hpp"


ChandelierHit::ChandelierHit(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mChandelierHit = TextureManager::find(ResKey::CChandelierHit);
  
  setColliderType(Collider::Rect);
  
}

void ChandelierHit::setup() {}

void ChandelierHit::update() {}

void ChandelierHit::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mChandelierHit.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mChandelierHit.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}

void ChandelierHit::onCollisionUpdate(const std::shared_ptr<Object> &compare)
{
  
}
