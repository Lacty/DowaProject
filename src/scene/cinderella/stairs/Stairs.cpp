
#include "Stairs.hpp"
#include "../../../object/Task.hpp"


Stairs::Stairs(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
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

void Stairs::onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
