
# pragma once

#include "../../../object/Object.hpp"
#include "../../../resource/Resource.hpp"

#include "cinder/gl/Texture.h"

class Piano: public Object
{
  ci::gl::Texture mPiano;
  bool mIsPlay;
  float mVolume;
  float mFadeSpeed;
  
  Audio mHousePiano;
  
public:
  
  Piano(const ci::Vec3f&, const ci::Vec3f&);

	void setup();
	void update();
	void draw();

void onCollisionUpdate(const std::shared_ptr<Object>& compare);
};
