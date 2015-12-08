
# pragma once

#include "../../object/Object.hpp"

class Floor2 : public Object
{
public:
  
  Floor2(ci::Vec3f mFloor2Pos, ci::Vec3f mFloor2Size);
  
  void setup();
  void update();
  void draw();
};

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
