

#include "Rotater.hpp"
#include "../../window/Window.hpp"


Rotater::Rotater() {
  mPos = ci::Vec3f(dowa::getWindowCenter(), 0);
  mSize = ci::Vec3f(150, 20, 1);
  mRotate = ci::Vec3f::zero();
  
  // あたり判定を使わないのでNoneを指定
  setColliderType(Collider::None);
}


void Rotater::setup() {}

void Rotater::update() {
  mRotate.z += 0.6f;
}

void Rotater::draw() {
  // mPosの位置で回転する方法
//  ci::gl::pushModelView();
//  
//  ci::gl::translate(mPos);
//  ci::gl::rotate(mRotate);
//  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
//  
//  ci::gl::popModelView();
  
  
  
  // 回転の中心をずらす方法
  ci::Vec3f offset(200, 0, 0);
  ci::gl::pushModelView();
  
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::translate(offset);
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  
  ci::gl::popModelView();
}


void Rotater::onCollisionUpdate(const std::shared_ptr<Object> &compare) {}