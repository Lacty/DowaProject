
#include "Stairs2.hpp"
#include "../../../object/Task.hpp"


Stairs2::Stairs2(const ci::Vec3f& mStairsPosf, const ci::Vec3f& mStairsSizef)
{
  mPos = mStairsPosf;
  mSize = mStairsSizef;
  
  setColliderType(Collider::Rect);
  
}

void Stairs2::setup() {}

void Stairs2::update()
{
  
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.y == -80 && mCinderellaPos.x > 3500 && mCinderellaPos.x < 4950)
  {
    mPos.x += 1.94f;
  }

}

void Stairs2::draw()
{
  ci::gl::pushModelView();
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_ZERO, GL_ONE);
  ci::gl::drawCube(mPos, mSize);
//  glDisable(GL_ZERO);
//  glDisable(GL_ONE);
  glDisable(GL_BLEND);
  
  ci::gl::popModelView();
}

void Stairs2::onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
