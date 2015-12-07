
# pragma once

#include "../../object/Object.hpp"

class Floor : public Object
{
public:
  
  Floor(ci::Vec3f mFloorPos, ci::Vec3f mFloorSize);
  
  void setup();
  void update();
  void draw();
};

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
