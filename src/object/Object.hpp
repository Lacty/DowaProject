
#pragma once
#include <string>


class Object {
public:
  enum class State {
    Awake,
    Active,
    Dead
  };
  
  enum class Collider {
    None,
    Rect,
    Circle
  };
  
  Object();
  
  void setState(const State& state);
  const State getState() const;
  
  const bool isAwake() const;
  const bool isActive() const;
  const bool isDead() const;
  
  void setColliderType(const Collider& type);
  const Collider getColliderType() const;
  
  const bool isColliderTypeNone() const;
  const bool isColliderTypeRect() const;
  const bool isColliderTypeCircle() const;
  
  void setName(const std::string& name);
  const std::string getName() const;
  
  virtual void setup() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual void onCollisionUpdate() {};
  
protected:
  std::string mName;
  State mState;
  Collider mCollider;
};