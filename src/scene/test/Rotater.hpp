
#pragma once
#include "../../object/Object.hpp"


class Rotater : public Object {
private:
public:
  Rotater();
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};