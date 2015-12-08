
#include "Floor2.hpp"
#include "../../object/Object.hpp"
#include "cinder/app/AppNative.h"
#include "../../resource/ResourceManager.hpp"

Floor2::Floor2(ci::Vec3f mFloor2Pos, ci::Vec3f mFloor2Size)
{
  mPos = mFloor2Pos;
  mSize = mFloor2Size;
  
  setColliderType(Collider::Rect); // 当たり判定
}

void Floor2::setup() {}
void Floor2::update() {}

void Floor2::draw()
{
  ci::gl::pushModelView();
  
  ci::gl::drawCube(mPos, mSize);
  
  ci::gl::popModelView();
}

void onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
