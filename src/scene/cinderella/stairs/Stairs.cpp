
#include "Stairs.hpp"

Stairs::Stairs(const ci::Vec3f& mStairsPosf, const ci::Vec3f& mStairsSizef)
{
  mPos = mStairsPosf;
  mSize = mStairsSizef;
  
  setColliderType(Collider::Rect);
}

void Stairs::setup() {}

void Stairs::update() {}

void Stairs::draw()
{
  ci::gl::pushModelView();
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_ZERO, GL_ONE);
  ci::gl::drawCube(mPos, mSize);
  glDisable(GL_ZERO);
  glDisable(GL_ONE);
  glDisable(GL_BLEND);
  
  ci::gl::popModelView();
}

void Stairs::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  
}
