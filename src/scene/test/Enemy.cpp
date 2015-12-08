
#include "Enemy.hpp"
#include "../../window/Window.hpp"


Enemy::Enemy() {
  mPos = ci::Vec3f(dowa::getWindowCenter().x + 100,
                   dowa::getWindowCenter().y, 0);
  mSize = ci::Vec3f(50, 50, 3);
  mColor = ci::Color(1, 0, 0);
  
  setColliderType(Collider::Rect);
}


void Enemy::setup() {}

void Enemy::update() {}

void Enemy::draw() {
  ci::gl::color(mColor);
  ci::gl::drawCube(mPos, mSize);
}


void Enemy::onCollisionUpdate(const std::shared_ptr<Object> &compare) {
  setState(State::Dead);
}