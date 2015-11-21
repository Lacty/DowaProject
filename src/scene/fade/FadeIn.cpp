
#include "FadeIn.hpp"
using namespace ci;
using namespace ci::app;
using namespace std;


FadeIn::FadeIn() {
	mPattern = FULL_SCREEN_FADE;

	mCanStart =
		mIsEnd =
		mIsEndInit = false;
}

bool FadeIn::getIsEnd() {
	return mIsEnd;
}

//---------------------------------------------

void FadeIn::setType(FadeType type,
	int time, Color color, bool isUseEasing) {

	switch (type) {

	case FadeType::None:
		break;

	case FadeType::FullScreen:
		fade = [=] {
			fullScreenFade(time, color, isUseEasing);
		};
		break;

	case FadeType::Circle:
		fade = [=] {
			circleScalingFade(time, color, isUseEasing);
		};
		break;

	case FadeType::Vell:
		fade = [=] {
			veilDownFade(time, color, isUseEasing);
		};
		break;

	case FadeType::FromLeft:
		fade = [=] {
			fromLeftCurtainFade(time, color, isUseEasing);
		};
		break;

	case FadeType::FromRight:
		fade = [=] {
			fromRightCurtainFade(time, color, isUseEasing);
		};
		break;

	case FadeType::BothSide:
		fade = [=] {
			centerCurtainFade(time, color, isUseEasing);
		};
		break;

	case FadeType::Hole:
		fade = [=] {
			pinHoleFade(time, 0.0f, 50, color, isUseEasing);
		};
		break;
	}

	fade();
}

//---------------------------------------------------
//TODO:Easingを使った中身の実装
//---------------------------------------------------

void FadeIn::fullScreenFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FULL_SCREEN_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos = Vec3f::zero();

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			//一度のみ初期化
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			//α値計算
			if ((int)mHideCube.size() > 0)
				mHideCube[0].mColor.a -= mSpeed;

			//α値が最大値(1.0f)になったら
			//fadeInを使用可能に変更
			if ((int)mHideCube.size() > 0) {
				if (mHideCube[0].mColor.a <= 0.0f) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}

		}

	}

}

void FadeIn::circleScalingFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CIRCLE_SCALING_FADE;
			mInterval = (60 * time);
			mSpeed = (1.0f / mInterval);

			//必要な個数生成
			mHideCircle.emplace_back();

			//生成したオブジェクトの初期化
			mHideCircle[0].mPos = Vec3f::zero();

			mHideCircle[0].mSize = windowOutPos;

			mHideCircle[0].mColor = ColorA(color, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if ((int)mHideCircle.size() > 0) {
				//α値計算
				mHideCircle[0].mColor.a -= mSpeed;
				//サイズ計算
				mHideCircle[0].mSize -= sizeChangeSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCircle[0].mColor.a <= 0.0f ||
					mHideCircle[0].mSize <= 0.0f) {

					mHideCircle.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::veilDownFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = VEIL_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowHeight() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.y -= mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCube[0].mPos.y <= -(float)getWindowHeight()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::fromLeftCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_LEFT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x -= mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCube[0].mPos.x <= -(float)getWindowWidth()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::fromRightCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_RIGHT_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed = ((float)getWindowWidth() / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(0.0f, 0.0f, 0.0f);

			mHideCube[0].mSize = Vec3f(
				(float)getWindowWidth(),
				(float)getWindowHeight(),
				0.1f);

			mHideCube[0].mColor = ColorA(color, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCube[0].mPos.x >= (float)getWindowWidth()) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

void FadeIn::centerCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CENTER_CURTAIN_FADE;
			mInterval = (60 * time);
			mSpeed =
				((float)(getWindowWidth() / 2) / mInterval);

			//必要な個数生成
			mHideCube.emplace_back();
			mHideCube.emplace_back();

			//生成したオブジェクトの初期化
			mHideCube[0].mPos =
				Vec3f(-quarterWindowSize, 0.0f, 0.0f);
			mHideCube[1].mPos =
				Vec3f(quarterWindowSize, 0.0f, 0.0f);

			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				mHideCube[i].mSize = Vec3f(
					(float)getWindowWidth() / 2,
					(float)getWindowHeight(),
					0.1f);

				mHideCube[i].mColor = ColorA(color, 1.0f);
			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCube.size() > 0) {
				//α値計算
				mHideCube[0].mPos.x -= mSpeed;
				mHideCube[1].mPos.x += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCube[0].mPos.x <=
					-(quarterWindowSize * 3)
					||
					mHideCube[1].mPos.x >=
					(quarterWindowSize * 3)) {

					mHideCube.clear();

					mCanStart = false;
					mIsEnd = true;
				}
			}

		}

	}

}

void FadeIn::pinHoleFade(
	int time, float space, const int slices,
	Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (space > windowOutPos) {
		space = 0.0f;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = PIN_HOLE_FADE;
			mInterval = (60 * time);
			mSpeed = (((float)getWindowWidth() - space) / mInterval);

			//必要な個数生成
			mHideCylinder.emplace_back();

			//生成したオブジェクトの初期化
			mHideCylinder[0].mStartPos = space;
			mHideCylinder[0].mEndPos = windowOutPos;
			mHideCylinder[0].mSliceCount = slices;
			mHideCylinder[0].mColor = ColorA(color, 1.0f);

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if ((int)mHideCylinder.size() > 0) {
				//サイズ計算
				mHideCylinder[0].mStartPos += mSpeed;

				//α値が最大値(1.0f)になったら
				//fadeInを使用可能に変更
				if (mHideCylinder[0].mStartPos >= windowOutPos) {

					mHideCylinder.clear();

					mCanStart = false;
					mIsEnd = true;
				}

			}

		}

	}

}

//---------------------------------------------

void FadeIn::draw() {

	if (!mCanStart)return;

	gl::pushModelView();
	gl::translate(getWindowCenter());
	gl::enableAlphaBlending();

	switch (mPattern) {

	case NONE:
		return;
		break;

	case FULL_SCREEN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			if (!mIsUseEasing) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
			if (mIsUseEasing) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(Vec3f(mHideEasingCube[i].mPos, 0),
					Vec3f(mHideEasingCube[i].mSize, 0));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case CIRCLE_SCALING_FADE:
		for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
			gl::color(mHideCircle[i].mColor);
			gl::drawSolidCircle(
				mHideCircle[i].mPos.xy(), mHideCircle[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case VEIL_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case FROM_LEFT_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case FROM_RIGHT_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case CENTER_CURTAIN_FADE:
		for (unsigned int i = 0; i < mHideCube.size(); ++i) {
			gl::color(mHideCube[i].mColor);
			gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
			gl::color(1.0f, 1.0f, 1.0f, 1.0f);
		}
		break;

	case PIN_HOLE_FADE:
		for (unsigned int i = 0; i < mHideCylinder.size(); ++i) {
			gl::rotate(Vec3f(90, 0, 0));
			gl::color(mHideCylinder[i].mColor);
			gl::drawCylinder(
				mHideCylinder[i].mStartPos,
				mHideCylinder[i].mEndPos,
				0.1f,
				mHideCylinder[i].mSliceCount);
			gl::color(Color(1, 1, 1));
		}
		break;
	}

	gl::disableAlphaBlending();
	gl::popModelView();

}

