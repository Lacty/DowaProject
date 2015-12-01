
#pragma once
#include "../Scene.hpp"
#include "../../device/Device.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>

#include "../../scene/SceneManager.hpp"



class Select : public Scene {
private:
	
	static Select& get();

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
	
	bool isOnCursor;
	bool isSelected;
	bool isDecided;


	struct Stage
	{
		ci::Vec3f pos;
		ci::Vec3f size;
		ci::Vec3f resize;
		ci::Vec3f resize_angle;

	};
	
	class Device;
public:
	
	Stage stage1;
	Stage stage2;
	Stage stage3;
	//git更新確認用
	Stage stage4;


	Select();
	//void 
	
	void update();
	void draw();

};