
#pragma once
#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"

class Result : public Scene 
{
private:
	int mChange;
	float mCount;
	float mr;

	ci::Rectf mFinpos;
	ci::Rectf mSelectpos;
	ci::Rectf mRetrypos;
	ci::Rectf mFontpos;
	
	enum mChange
	{
		mScreen1,
		mScreen2,
		mScreen3
	};
public:
  Result();
  ~Result();
  
  void update();
  void draw();
};