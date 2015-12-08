
#pragma once
#include "../../object/Object.hpp"


class Enemy : public Object {
private:
public:
  Enemy();
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};