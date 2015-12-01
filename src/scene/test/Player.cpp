
#include "Player.hpp"
#include "../../object/Task.hpp"
#include "../../device/Device.hpp"


Player::Player() {
  mPos = ci::Vec3f(0, 0, 0);
  mSize = ci::Vec3f(50, 50, 2);
  
  setColliderType(Collider::Rect);
}


void Player::setup() {}

void Player::update() {
  static bool touch = true;
  mPos.x += touch ? 1 : 0;
  
  if (!dowa::Device::isTouchBegan()) return;
  touch = !touch;
}

void Player::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(mPos);
  ci::gl::color(1, 1, 1);
  ci::gl::drawCube(ci::Vec3f::zero(), mSize);
  ci::gl::popModelView();
}


void Player::onCollisionUpdate(const std::shared_ptr<Object>& compare) {
  //compare->setState(State::Dead);
}