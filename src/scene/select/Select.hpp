
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
	
	/*
	ci::Rectf mBackgroundapos;
	ci::Rectf mStageinfpos;
	ci::Rectf mStage1pos;
	ci::Rectf mStage2pos;
	ci::Rectf mStage3pos;
	*/
public:
	
	Stage stage1;
	Stage stage2;
	Stage stage3;
	
	Select();
	void update();
	void draw();
};