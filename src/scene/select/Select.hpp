
#pragma once
#include "../Scene.hpp"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

class Select : public Scene {
private:
  ci::gl::Texture mBackGround;
  ci::gl::Texture mBook;
  ci::gl::Texture mTitle;

  ci::Rectf mPlaneBG;
  ci::Rectf mPlaneBook;
  ci::Rectf mPlaneTitle;
	
public:
	Select();
  ~Select();
  
	void update();
	void draw();
};
