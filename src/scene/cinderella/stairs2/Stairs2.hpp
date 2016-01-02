
#pragma once

#include "../../../object/Object.hpp"

class Stairs2 : public Object
{
public:
  
  Stairs2(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);

};
