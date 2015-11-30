
#pragma once
#include "../Scene.hpp"
#include "Coordinate.hpp"
#include "../../device/Device.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>

#include "../../scene/SceneManager.hpp"


class Device;
class Select : public Scene {
private:
	Device* selectDevice;


	float ry;
	float y_angle;
	float mDeviceWindowHeight, mDeviceWindowWidth;

	

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

	
	
	class Device;
public:
	
	Stage stage1;
	Stage stage2;
	Stage stage3;
	//git更新確認用
	Stage stage4;

	Select();

	void keyDown(ci::app::KeyEvent event);
	void mouseDown(ci::app::MouseEvent event);
	void update();
	void draw();
};