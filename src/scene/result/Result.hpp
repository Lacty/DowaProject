
#pragma once
#include "../Scene.hpp"

class Result : public Scene 
{
private:
	int mChange;
	int mCount;
	float mr;
	
	

	enum mChange
	{
		mScreen1,
		mScreen2,
		mScreen3
	};
public:
  Result();
  
  void update();
  void draw();
};