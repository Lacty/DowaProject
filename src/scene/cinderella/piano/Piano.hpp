
# pragma once

#include "../../../object/Object.hpp"

#include "cinder/gl/Texture.h"

class Piano: public Object
{
  ci::gl::Texture mPiano;
  
  std::string mBallStr;
  
public:
  
  Piano(const ci::Vec3f&, const ci::Vec3f&);

	void setup();
	void update();
	void draw();

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
