
#pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Orchestra : public Object
{
  ci::gl::Texture mOrchestra1;
  ci::gl::Texture mOrchestra2;
  
  std::string mOrchestraName;
  
  void drawOrchestra(const ci::gl::Texture&);
  
public:
  
  Orchestra(const ci::Vec3i&, const ci::Vec3i&, const std::string&);
  
  void setup();
  void update();
  void draw();
  
};
