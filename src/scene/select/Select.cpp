
#include "Select.hpp"


Select::Select() {

	my_angle = 0.0f;
	mry = 0.0f;
	//mtouchPos = dowa::Device::getTouchPos();//ci::Vec2f(0.0f, 0.0f);

	mDeviceWindowHeight = dowa::getWindowHeight();
	mDeviceWindowWidth = dowa::getWindowWidth();

	//stage1.pos = ci::Vec3f(150.0f, 250.0f, 0.0f); // nothing translate(test)
	stage1.pos = ci::Vec3f(120.0f, 200.0f, 0.0f);
	stage1.size = ci::Vec3f(200.0f, 75.0f, 0.0f);
	stage1.resize = ci::Vec3f::zero()/*(10.0f, 10.0f, 10.0f)*/;
	stage1.resize_angle = ci::Vec3f(0.0f, 0.0f, 0.0f);

	

	//mStage1pos = ci::Rectf(stage1.pos.x, stage1.pos.y, 
	//	                 stage1.size.x, stage1.size.y);

	stage2.pos = ci::Vec3f(320.0f, 75.0f, 0.0f),
		stage2.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	stage3.pos = ci::Vec3f(520.0f, 200.0f, 0.0f);
	stage3.size = ci::Vec3f(200.0f, 75.0f, 0.0f);

	isSelected = false;
	isDecided = false;

	mSelectedStage_id = mNone;
}

void Select::update() {

	//setNextScene(SceneType::GameMain, FadeType::None);
	//-------------------------------------------------------------
	//move up and down
	mry = std::cos(my_angle) * 10.0f;
	my_angle += 0.0f;//005f;
	//-------------------------------------------------------------
	//scale up or down
	stage1.resize.x = std::sin(stage1.resize_angle.x) * 10.0f;
	stage1.resize.y = std::sin(stage1.resize_angle.y) * 10.0f;
	if (!isSelected)
	{
		stage1.resize_angle.x += 0.005f;
		stage1.resize_angle.y += 0.005f;
	}
	//-------------------------------------------------------------
	//touch
	if (dowa::Device::isTouchBegan())
	{
		std::cout << "touched" << std::endl;
		//SceneManager::create(SceneType::Select);
	
		mtouchPos = dowa::Device::getTouchPos();
	
		if (mtouchPos.x >= stage1.pos.x -100.0f&& mtouchPos.x <=stage1.pos.x + stage1.size.x - 100.0f
			&& mtouchPos.y >= stage1.pos.y - 25.0f && mtouchPos.y <=  stage1.pos.y + stage1.size.y-25.0f)
		{
			SceneManager::create(SceneType::Result);
		}

		if (mtouchPos.x >= stage2.pos.x - 100.0f&& mtouchPos.x <= stage2.pos.x + stage2.size.x - 100.0f
			&& mtouchPos.y >= stage2.pos.y - 25.0f && mtouchPos.y <= stage2.pos.y + stage2.size.y - 25.0f)
		{
			SceneManager::create(SceneType::Result);
		}
		if (mtouchPos.x >= stage3.pos.x-100.0f && mtouchPos.x <= stage3.pos.x + stage3.size.x -100.0f
			&& mtouchPos.y >= stage3.pos.y - 25.0f && mtouchPos.y <= stage3.pos.y + stage3.size.y - 25.0f)
		{
			SceneManager::create(SceneType::Result);
		}
//-----------------------------------------------------------------
		if (mtouchPos.x >= 200 && mtouchPos.x <= 300
			&& mtouchPos.y >= 200 && mtouchPos.y <= 300)
		{
		//	SceneManager::create(SceneType::Result);
		}
//------------------------------------------------------------------

	}
	std::cout << "touchpos:" << mtouchPos << std::endl;
}

void Select::draw() {
		
	//background
	ci::gl::pushModelView();
	ci::gl::color(ci::Color(1, 1, 1));
	ci::gl::drawCube(ci::Vec3f(mDeviceWindowWidth / 2, mDeviceWindowHeight / 2-90, 0.0f), ci::Vec3f(800, 500, 0));
	ci::gl::popModelView();

	switch (mSelectedStage_id){
		//selected stage
	case mNone:
		ci::gl::pushModelView();
		ci::gl::color(ci::Color(0, 0, 1));
		ci::gl::drawCube(ci::Vec3f(0, 375.0f , 0), ci::Vec3f(1280, 210, 0));
		ci::gl::popModelView();
		break;

	case mStage1:
		ci::gl::pushModelView();
		ci::gl::color(ci::Color(0.3f, 0, 1));
		ci::gl::drawCube(ci::Vec3f(0, 375.0f, 0), ci::Vec3f(1280, 210, 0));
		ci::gl::popModelView();
		break;

	case mStage2:
		ci::gl::pushModelView();
		ci::gl::color(ci::Color(0, 0.3f, 1));
		ci::gl::drawCube(ci::Vec3f(0, 375.0f, 0), ci::Vec3f(1280, 210, 0)); 
		ci::gl::popModelView();
		break;

	case mStage3:
		ci::gl::pushModelView();
		ci::gl::color(ci::Color(0, 0, 0.3f));
		ci::gl::drawCube(ci::Vec3f(0, 375.0f, 0), ci::Vec3f(1280, 210, 0));
		ci::gl::popModelView();
		break;
	}
	//stage1
	ci::gl::pushModelView();
	ci::gl::color(ci::Color(1, 1, 0));
	ci::gl::drawCube(ci::Vec3f(stage1.pos.x, stage1.pos.y + mry, stage1.pos.z),
		ci::Vec3f(stage1.size.x /*+ stage1.resize.x*/, stage1.size.y/* + stage1.resize.y*/, stage1.size.z));
	ci::gl::popModelView();

	//stage2
	ci::gl::pushModelView();
	ci::gl::color(ci::Color(1, 0, 0));
	ci::gl::drawCube(ci::Vec3f(stage2.pos.x, stage2.pos.y + mry, stage2.pos.z),
		ci::Vec3f(stage2.size.x, stage2.size.y, stage2.size.z));
	ci::gl::popModelView();

	//stage3
	ci::gl::pushModelView();
	ci::gl::color(ci::Color(1, 1, 0));
	ci::gl::drawCube(ci::Vec3f(stage3.pos.x, stage3.pos.y + mry, stage3.pos.z),
		ci::Vec3f(stage3.size.x, stage3.size.y, stage3.size.z));
	ci::gl::popModelView();
}


