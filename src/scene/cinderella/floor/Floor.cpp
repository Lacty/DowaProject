
#include "Floor.hpp"

#include "../../../resource/Resource.hpp"


Floor::Floor(const  ci::Vec3f& mFloorPos, const ci::Vec3f& mFloorSize)
{
  mPos = mFloorPos;
  mSize = mFloorSize;
  
  setColliderType(Collider::Rect);
}

void Floor::setup() {}
void Floor::update() {}

void Floor::draw()
{
  ci::gl::pushModelView();
  
  glEnable(GL_BLEND);
//  glBlendFunc(GL_ZERO, GL_ONE);
  ci::gl::drawCube(mPos, mSize);
  glDisable(GL_ZERO);
  glDisable(GL_ONE);
  glDisable(GL_BLEND);
  
  ci::gl::popModelView();
}

void onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
