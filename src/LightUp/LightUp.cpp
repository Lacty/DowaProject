
#include "LightUp.hpp"


LightUp::LightUp(){}

void LightUp::setDate(
	ci::Surface surface,
	ci::Vec2f pos, ci::Vec2f size,
	ci::Color color) {

	mSurface = surface;
	mInput = ci::toOcv(
		mSurface, cv::IMREAD_UNCHANGED);

	for (int y = 0; y < mInput.rows; y++)
	{
		for (int x = 0; x < mInput.cols; x++)
		{
			for (int c = 0; c < mInput.channels() - 1; c++)
			{
				if (mInput.data[
					y * mInput.step +
						x * mInput.elemSize() + c] != 0)
				{
					mInput.data[
						y * mInput.step +
							x * mInput.elemSize() + c] = 255;
				}
			}
		}
	}

	mLightForm = ci::gl::Texture(ci::fromOcv(mInput));

	//-------------------------

	mRectStatePos = pos;
	mRectSize = size * mResize;
	mColor = color;

}

void LightUp::setDate(
	std::string texturePass,
	ci::Vec2f pos, ci::Vec2f size,
	ci::Color color) {

	mSurface = ci::loadImage(ci::app::loadAsset(texturePass));
	mInput = ci::toOcv(
		mSurface, cv::IMREAD_UNCHANGED);

	for (int y = 0; y < mInput.rows; y++)
	{
		for (int x = 0; x < mInput.cols; x++)
		{
			for (int c = 0; c < mInput.channels() - 1; c++)
			{
				if (mInput.data[
					y * mInput.step +
						x * mInput.elemSize() + c] != 0)
				{
					mInput.data[
						y * mInput.step +
							x * mInput.elemSize() + c] = 255;
				}
			}
		}
	}

	mLightForm = ci::gl::Texture(ci::fromOcv(mInput));


	mRectStatePos = pos;
	mRectSize = size * mResize;
	mColor = color;

}

void LightUp::setIsActive(bool value) {
	isActive = value;
}

void LightUp::draw() {

	if (!isActive)return;

	auto rect = ci::Rectf(
		(mRectStatePos - (mRectSize / 2)),
		(mRectStatePos - (mRectSize / 2)) + mRectSize);

	ci::ColorA lightColor =
		ci::ColorA(mColor, 1.0f);

	//------------------------------------------

	ci::gl::pushModelView();

	ci::gl::enableAlphaBlending();
	ci::gl::color(lightColor);

	ci::gl::enable(GL_TEXTURE_2D);
	mLightForm.bind();

	ci::gl::drawSolidRect(rect);

	mLightForm.unbind();
	ci::gl::disable(GL_TEXTURE_2D);

	ci::gl::color(1.0f, 1.0f, 1.0f, 1.0f);
	ci::gl::disableAlphaBlending();

	ci::gl::popModelView();
}

