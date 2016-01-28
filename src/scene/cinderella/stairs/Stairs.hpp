
#pragma once

#include "../../../object/Object.hpp"

class Stairs : public Object
{
public:
  
  Stairs(const ci::Vec3f&, const ci::Vec3f&);
  
  void setup();
  void update();
  void draw();
  
  void onCollisionUpdate(const std::shared_ptr<Object>&);

};
