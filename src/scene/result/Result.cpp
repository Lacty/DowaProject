
#include "Result.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

Result::Result()
{
	mChange = mScreen1;  

	mCount = 0.0f;
	mr = 0.0f;

	//äeâÊëúÇÃç¿ïW
	mSelectpos = ci::Rectf(0, 0, 200, 100);
	mRetrypos = ci::Rectf(-250, 0, -50, 100);
	mFinpos = ci::Rectf(150,150,250,200);
	mFontpos = ci::Rectf(-150, -100, 150, 0);
}

void Result::update() 
{
	mCount += 0.5f;
	mr += 0.1f;

	switch (mChange)
	{
	case mScreen1:
		if (mCount == 200.0f)
		{
			mChange = mScreen2;

			 mr = 0.0f;

		}
		break;

	case mScreen2:
		if (mCount == 500.0f)
		{
			mChange = mScreen3;
			mr = 0.0f;
		}
		break;

	case mScreen3:
		if (dowa::Device::isTouchBegan())
		{
			SceneManager::create(SceneType::Title);
		}
		break;

	}
}

void Result::draw() 
{	
	std::cout << "count" << mCount << std::endl;
	switch (mChange)
	{
	case mScreen1:

		ci::gl::pushModelView();

		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::translate(ci::Vec3f(0.0f,0.0f,mr));
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Font), mFontpos);
		ci::gl::popModelView();
		break;

	case mScreen2:

		//background
		ci::gl::pushModelView();
		ci::gl::translate(ci::Vec3f(0.0f, 0.0f, mr));
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Back), ci::app::getWindowBounds());

		ci::gl::popModelView();

		break;
	case mScreen3:
		//background
		ci::gl::pushModelView();
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Back), ci::app::getWindowBounds());
		ci::gl::popModelView();

		//fin
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Fin), mFinpos);
		ci::gl::popModelView();

		//selection
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Select), mSelectpos);
		ci::gl::popModelView();

		//retry
		
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(1, 1, 1));
		ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Retry), mRetrypos);
		ci::gl::popModelView();

		break;
	}
}