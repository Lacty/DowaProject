
#include "Select.hpp"



Select::Select() {

	y_angle = 0.0f;
	ry = 0.0f;



	mDeviceWindowHeight = ci::app::getWindowHeight();
	mDeviceWindowWidth = ci::app::getWindowWidth();


	stage1.pos = ci::Vec3f(-200.0f, 0.0f, 0.0f);
	stage1.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	stage2.pos = ci::Vec3f(0.0f, -150.0f, 0.0f),
		stage2.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	stage3.pos = ci::Vec3f(200.0f, 0.0f, 0.0f);
	stage3.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	
	isOnCursor = false;
	isSelected = false;
	isDecided = false;

	mSelectedStage_id = mStage3;
}

void Select::keyDown(ci::app::KeyEvent event)
{


	if (event.getCode() == ci::app::KeyEvent::KEY_SPACE)
	{

	}

}

void Select::update() {
	//setNextScene(SceneType::GameMain, FadeType::None);
	ry = std::sin(y_angle) * 10.0f;
	y_angle += 0.005f;
	if (isDecided==true)
	{
		
			SceneManager::create(SceneType::GameMain);
		
	}
	
}

void Select::mouseDown(ci::app::MouseEvent event)
{

	if (dowa::Device::isTouchBegan){
		if (event.getX() >= stage1.pos.x && event.getX() <= stage1.pos.x + stage1.size.x
			&& event.getY() >= stage1.pos.y && event.getY() <= stage1.pos.y + stage1.size.y)
		{
			isDecided = true;

		}
	}
}


void Select::draw() {

	//background
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 1, 1));
	ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(800, 500, 0));
	ci::gl::popModelView();

	switch (mSelectedStage_id){
		//selected stage
	case mNone:
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 0, 1));
		ci::gl::drawCube(ci::Vec3f(0, mDeviceWindowHeight / 3, 0), ci::Vec3f(600, 250, 0));
		ci::gl::popModelView();
		break;

	case mStage1:
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0.3f, 0, 1));
		ci::gl::drawCube(ci::Vec3f(0, mDeviceWindowHeight / 3, 0), ci::Vec3f(600, 250, 0));
		ci::gl::popModelView();
		break;

	case mStage2:
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 0.3f, 1));
		ci::gl::drawCube(ci::Vec3f(0, mDeviceWindowHeight / 3, 0), ci::Vec3f(600, 250, 0));
		ci::gl::popModelView();
		break;

	case mStage3:
		ci::gl::pushModelView();
		ci::gl::translate(ci::app::getWindowCenter());
		ci::gl::color(ci::Color(0, 0, 0.3f));
		ci::gl::drawCube(ci::Vec3f(0, mDeviceWindowHeight / 3, 0), ci::Vec3f(600, 250, 0));
		ci::gl::popModelView();
		break;
	}
	//stage1
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 1, 0));
	ci::gl::drawCube(ci::Vec3f(stage1.pos.x, stage1.pos.y + ry, stage1.pos.z),
		ci::Vec3f(stage1.size.x, stage1.size.y, stage1.size.z));
	ci::gl::popModelView();

	//stage2
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 0, 0));
	ci::gl::drawCube(ci::Vec3f(stage2.pos.x, stage2.pos.y + ry, stage2.pos.z),
		ci::Vec3f(stage2.size.x, stage2.size.y, stage2.size.z));
	ci::gl::popModelView();

	//stage3
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 1, 0));
	ci::gl::drawCube(ci::Vec3f(stage3.pos.x, stage3.pos.y + ry, stage3.pos.z),
		ci::Vec3f(stage3.size.x, stage3.size.y, stage3.size.z));
	ci::gl::popModelView();

	/*
	//for Cursor  
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color();
	ci::gl::drawCube();
	ci::gl::popModelView();

	*/


}