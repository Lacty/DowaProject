
#include "Object.hpp"
#include "Task.hpp"


Object::Object() :
mState(State::Awake),
mCollider(Collider::None) {}

void Object::setState(const State& state) {
  mState = state;
}

const Object::State Object::getState() const {
  return mState;
}

const bool Object::isAwake() const {
  return mState == State::Awake;
}

const bool Object::isActive() const {
  return mState == State::Active;
}

const bool Object::isDead() const {
  return mState == State::Dead;
}

void Object::setColliderType(const Collider& type) {
  mCollider = type;
}

const Object::Collider Object::getColliderType() const {
  return mCollider;
}

const bool Object::isColliderTypeNone() const {
  return mCollider == Collider::None;
}

const bool Object::isColliderTypeRect() const {
  return mCollider == Collider::Rect;
}

const bool Object::isColliderTypeCircle() const {
  return mCollider == Collider::Circle;
}

void Object::setName(const std::string& name) {
  mName = name;
}

const std::string Object::getName() const {
  return mName;
}

const ci::Vec3f Object::getPos() const {
  return mPos;
}

const ci::Vec3f Object::getSize() const {
  return mSize;
}

const ci::Vec3f Object::getRotate() const {
  return mRotate;
}