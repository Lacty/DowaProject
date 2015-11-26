
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Timeline.h"
#include "cinder/Tween.h"

#include <vector>
#include <functional>


enum class FadeType {
	None,

	FullScreen,
	Circle,
	Vell,
	FromLeft,
	FromRight,
	BothSide,
	Hole
};

class FadeBase {

protected:

	enum FadeTypeName {
		//無し
		NONE,
		//全画面のα値変化でfade
		FULL_SCREEN_FADE,
		//画面の中心から円が出て、拡縮とα値変化でfade
		CIRCLE_SCALING_FADE,
		//画面上から垂れ幕(Cube)が出てfade
		VEIL_FADE,
		//左からカーテンの様にfade
		FROM_LEFT_CURTAIN_FADE,
		//右からカーテンの様にfade
		FROM_RIGHT_CURTAIN_FADE,
		//センターカーテンの様に横からfade
		CENTER_CURTAIN_FADE,
		//ピンホール型のfade(改善の余地有)
		PIN_HOLE_FADE,
	};
	FadeTypeName mPattern;

	//-----------------------------------------------

	//Objects
	struct ObjectBase {
		ci::Vec3f mPos;
		ci::ColorA mColor;
	};

	struct CubeDate :ObjectBase {
		ci::Vec3f mSize;
	};
	std::vector<CubeDate>mHideCube;
	struct CircleDate :ObjectBase {
		float mSize;
	};
	std::vector<CircleDate>mHideCircle;
	struct CylinderDate {
		float mStartPos;
		float mEndPos;
		int mSliceCount;
		ci::ColorA mColor;
	};
	std::vector<CylinderDate>mHideCylinder;

	//EasingObjects
	struct EasingObjectBase {
		ci::Anim<ci::Vec2f>mPos;
		ci::Anim<ci::Vec2f>mEndPos;
		ci::ColorA mColor;
		ci::Anim<float>mAlpha;
		ci::Anim<float>mEndAlpha;
	};

	struct EasingCubeDate :EasingObjectBase {
		ci::Anim<ci::Vec2f>mSize;
		ci::Anim<ci::Vec2f>mEndSize;
	};
	std::vector<EasingCubeDate>mHideEasingCube;
	struct EasingCircleDate :EasingObjectBase {
		ci::Anim<float>mSize;
		ci::Anim<float>mEndSize;
	};
	std::vector<EasingCircleDate>mHideEasingCircle;
	struct EasingCylinderDate {
		ci::Anim<float>mStartPos;
		ci::Anim<float>mEndStartPos;
		ci::Anim<float>mEndPos;
		int mSliceCount;
		ci::ColorA mColor;
	};
	std::vector<EasingCylinderDate>mHideEasingCylinder;

	//Control of the function
	bool mCanStart;
	bool mIsEnd;
	bool mIsEndInit;

	bool mIsUseEasing;
	bool mIsEndEasing;

	int mInterval;
	float mSpeed;
	
	int mTime;
	ci::Color mColorIn;
	bool mIsUseEasingIn;

};

//-----------------------------------------------------

static void lightUp(ci::Rectf rectState, ci::Color color) {

	ci::ColorA lightColor =
		ci::ColorA(color, 0.2f);

	ci::gl::pushModelView();

	ci::gl::translate(ci::app::getWindowCenter());
	ci::gl::enableAlphaBlending();
	ci::gl::color(lightColor);

	ci::gl::drawSolidRect(rectState);

	ci::gl::color(1.0f, 1.0f, 1.0f, 1.0f);
	ci::gl::disableAlphaBlending();

	ci::gl::popModelView();

}