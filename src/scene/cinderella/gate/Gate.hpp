
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Gate : public Object
{
  
  ci::gl::Texture mGate;
  ci::gl::Texture mGateBack;
  
  std::string mGateName;
  
  void drawGate(const ci::gl::Texture&);
  
public:
  
  Gate(const ci::Vec3f&, const ci::Vec3f&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
};
