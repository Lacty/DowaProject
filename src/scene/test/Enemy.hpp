
#pragma once
#include "../../object/Object.hpp"


class Enemy : public Object {
private:
public:
  Enemy();
  
  void setup();
  void update();
  void draw();
  
  int getX() { return mPos.x; }
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
