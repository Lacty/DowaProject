
#pragma once
#include "../../object/Object.hpp"


class T : public Object {
private:

public:
  T();
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
