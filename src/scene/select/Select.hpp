
#pragma once
#include "../Scene.hpp"
#include "../../device/Device.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>
#include "../../scene/SceneManager.hpp"
#include "../../window/Window.hpp"
#include "../../resource/ResourceManager.hpp"

class Select : public Scene {
private:
	
	float mry;
	float my_angle;
	float mDeviceWindowHeight, mDeviceWindowWidth;
	ci::Vec2f mtouchPos;
	int mSelectedStage_id;
	
	enum Stage_id
	{
		mNone,
		mStage1,
		mStage2,
		mStage3,
	};
	
	bool isSelected;
	bool isDecided;

	struct Stage
	{
		ci::Vec3f pos;
		ci::Vec3f size;
		ci::Vec3f resize;
		ci::Vec3f resize_angle;

	};

	ci::Rectf mStageSelectBack;

	ci::Rectf mStageCinderellaBook; //use stage2
	ci::Rectf mStageCinderella;  
	ci::Rectf mStageCinderellaLogo;
	//ci::Rectf m;
public:
	
	Stage stage1;
	Stage stage2;//Logo
	Stage stage3;

	Stage book1;
	Stage book2;
	Stage book3;
	
	Select();
	void update();
	void draw();
};