
#pragma once
#include "../../object/Object.hpp"


class Player : public Object {
private:
public:
  Player();
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
