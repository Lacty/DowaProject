
#include "WoodenBox.hpp"

#include "../../../resource/Resource.hpp"


WoodenBox::WoodenBox(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mWoodenBox = TextureManager::find(ResKey::CWoodenBox);
  
  
  setColliderType(Collider::Rect);
  
}

void WoodenBox::setup() {}

void WoodenBox::update() {}

void WoodenBox::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mWoodenBox.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mWoodenBox.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void WoodenBox::onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
