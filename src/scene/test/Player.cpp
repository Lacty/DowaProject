
#include "Player.hpp"
#include "../../window/Window.hpp"

#include "Enemy.hpp"
#include "../../object/Task.hpp"


Player::Player() {
  mPos = ci::Vec3f(dowa::getWindowCenter(), 0);
  mSize = ci::Vec3f(50, 50, 2);
  mColor = ci::Color(1, 1, 1);
  
  setColliderType(Collider::Rect);
}

void Player::setup() {}

void Player::update() {
  mPos.x++;
  
  Task::find("Enemy")->getPos();
}

void Player::draw() {
  ci::gl::color(mColor);
  ci::gl::drawCube(mPos, mSize);
}


void Player::onCollisionUpdate(const std::shared_ptr<Object> &compare) {}