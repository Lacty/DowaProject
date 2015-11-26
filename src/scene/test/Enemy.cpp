
#include "Enemy.hpp"


Enemy::Enemy() {
  mPos = ci::Vec3f(ci::app::getWindowCenter().x + 100,
                   ci::app::getWindowCenter().y, 0);
  mSize = ci::Vec3f(50, 50, 50);
  
  setColliderType(Collider::Rect);
}


void Enemy::setup() {}

void Enemy::update() {}

void Enemy::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(mPos);
  ci::gl::color(1, 0, 0);
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  ci::gl::popModelView();
}


void Enemy::onCollisionUpdate(const std::shared_ptr<Object>& compare) {}