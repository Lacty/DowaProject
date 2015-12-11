
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

#include "../resource/ResourceManager.hpp"

#include "CinderOpenCV.h"

class LightUp {

private:

	ci::Vec2f mRectStatePos;
	ci::Vec2f mRectSize;
	ci::Color mColor;

	const float mResize = 1.2f;

	ci::gl::Texture mLightForm;

	bool isActive = false;

	cv::Mat mInput;
	ci::Surface mSurface;

public:

	LightUp();

	void setDate(
		ci::Surface, ci::Vec2f, ci::Vec2f, ci::Color);

	void setDate(
		std::string, ci::Vec2f, ci::Vec2f, ci::Color);

	void setIsActive(bool);

	void draw();

};

