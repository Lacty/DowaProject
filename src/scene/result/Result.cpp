
#include "Result.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

Result::Result() 
{
	mChange = mScreen1;

	mCount = 0;
	mr = 0.0f;
	
	
}

void Result::update() 
{
	mCount += 1;
	mr += 0.5f;

	//âÊñ êÿÇËë÷Ç¶
	if (Device::isTouchBegan())
	{
		//gamemainâÊñ Ç÷
		SceneManager::create(SceneType::GameMain);

	}



	switch (mChange)
	{
	case mScreen1:
		if (mCount == 100)
		{
			mChange = mScreen2;

			mr = 0.0f;
		}
		break;

	case mScreen2:
		if (mCount == 200)
		{
			mChange = mScreen3;
			mr = 0.0f;
		}
		break;

	case mScreen3:
		if (mCount == 300)
		{
			mChange = mScreen4;
			mr = 0.0f;
		}
		break;

	case mScreen4:
		if (mCount == 400)
		{
			mChange = mScreen5;
			mr = 0.0f;
		}
		break;

	case mScreen5:
		if (mCount == 500)
		{
			mChange = mScreen6;
			mr = 0.0f;
		}
		break;
	case mScreen6:
		
		break;
	}
  
}

void Result::draw() {
	switch (mChange)
	{
	case mScreen1:
		ci::gl::pushModelView();

		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f,0.0f,mr));
		ci::gl::color(ci::Color(1, 1, 1));
		
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(300, 100, 100));
	
		ci::gl::popModelView();
		break;

	case mScreen2:
	
	
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f, 0.0f, mr));
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(300, 100, 100));
	
		ci::gl::popModelView();
		break;

	case mScreen3:
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f, 0.0f, mr));
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(300, 100, 100));
	
		ci::gl::popModelView();
		break;

	case mScreen4:
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f, 0.0f, mr));
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(300, 100, 100));
	
		ci::gl::popModelView();
		break;

	case mScreen5:
		//background
		ci::gl::pushModelView();
		
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f, 0.0f, mr));
		ci::gl::color(ci::Color(0, 1, 1));
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(800, 500, 0));
		
		ci::gl::popModelView();

		break;
	case mScreen6:
		//background
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 1, 1));
		ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(800, 500, 0));
	
		ci::gl::popModelView();

		//fin
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(1, 0, 0));
		ci::gl::drawCube(ci::Vec3f(200, 150, 0), ci::Vec3f(130, 100, 0));
	
		ci::gl::popModelView();

		//selection
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 0, 1));
		ci::gl::drawCube(ci::Vec3f(150, 0, 0), ci::Vec3f(200, 100, 0));
	
		ci::gl::popModelView();

		//retry
		ci::gl::pushModelView();
	
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 0, 0));
		ci::gl::drawCube(ci::Vec3f(-150, 0, 0), ci::Vec3f(200, 100, 0));
	
		ci::gl::popModelView();


		break;
	}
}