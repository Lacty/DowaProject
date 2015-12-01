
#include "Select.hpp"



Select::Select() {

	

	my_angle = 0.0f;
	mry = 0.0f;
	//mtouchPos = dowa::Device::getTouchPos();//ci::Vec2f(0.0f, 0.0f);

	mDeviceWindowHeight = ci::app::getWindowHeight();
	mDeviceWindowWidth = ci::app::getWindowWidth();


	stage1.pos = ci::Vec3f(-200.0f, 0.0f, 0.0f);
	stage1.size = ci::Vec3f(200.0f, 75.0f, 0.0f);
	stage1.resize = ci::Vec3f(10.0f, 10.0f, 10.0f);
	stage1.resize_angle = ci::Vec3f(0.0f, 0.0f, 0.0f);

	stage2.pos = ci::Vec3f(0.0f, -150.0f, 0.0f),
		stage2.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	stage3.pos = ci::Vec3f(200.0f, 0.0f, 0.0f);
	stage3.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	
	isOnCursor = false;
	isSelected = false;
	isDecided = false;

	mSelectedStage_id = mStage3;
}

void Select::update() {
	//setNextScene(SceneType::GameMain, FadeType::None);
	//-------------------------------------------------------------
	//上下微動
	mry = std::cos(my_angle) * 10.0f;
    my_angle += 0.005f;
	//-------------------------------------------------------------
	//-------------------------------------------------------------
	//拡大縮小
	stage1.resize.x = std::sin(stage1.resize_angle.x) * 10.0f;
	stage1.resize.y = std::sin(stage1.resize_angle.y) * 10.0f;
	if (!isOnCursor)
	{
		stage1.resize_angle.x += 0.005f;
		stage1.resize_angle.y += 0.005f;
	}
	//-------------------------------------------------------------
	
	
	if (dowa::Device::isTouchBegan())
	{
		std::cout << "タッチしました" << std::endl;
		//SceneManager::create(SceneType::Select);
	
		mtouchPos = dowa::Device::getTouchPos();
		if (mtouchPos.x >= stage1.pos.x && mtouchPos.x <= stage1.size.x
			&& mtouchPos.y >= stage1.pos.y && mtouchPos.y <= stage1.size.y)
		{
			SceneManager::create(SceneType::Result);
		}
		
	}
	
	
	std::cout << "タッチした位置:" << mtouchPos << std::endl;

	

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
	ci::gl::drawCube(ci::Vec3f(stage1.pos.x, stage1.pos.y + mry, stage1.pos.z),
		ci::Vec3f(stage1.size.x + stage1.resize.x, stage1.size.y + stage1.resize.y, stage1.size.z));
	ci::gl::popModelView();

	//stage2
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 0, 0));
	ci::gl::drawCube(ci::Vec3f(stage2.pos.x, stage2.pos.y + mry, stage2.pos.z),
		ci::Vec3f(stage2.size.x, stage2.size.y, stage2.size.z));
	ci::gl::popModelView();

	//stage3
	ci::gl::pushModelView();
	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::color(ci::Color(1, 1, 0));
	ci::gl::drawCube(ci::Vec3f(stage3.pos.x, stage3.pos.y + mry, stage3.pos.z),
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