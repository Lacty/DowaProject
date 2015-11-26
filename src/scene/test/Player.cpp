
#include "Player.hpp"
#include "../../object/Task.hpp"


Player::Player() {
  mPos = ci::Vec3f(ci::app::getWindowCenter(), 0);
  mSize = ci::Vec3f(50, 50, 50);
  
  setColliderType(Collider::Rect);
}


void Player::setup() {}

void Player::update() {
  mPos.x += 1;
}

void Player::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(mPos);
  ci::gl::color(1, 1, 1);
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  ci::gl::popModelView();
}


void Player::onCollisionUpdate(const std::shared_ptr<Object>& compare) {
  compare->setState(State::Dead);
}