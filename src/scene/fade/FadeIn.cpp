
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
		return;
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
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FULL_SCREEN_FADE;

			if (!isUseEasing) {
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
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				//必要な個数生成
				mHideEasingCube.emplace_back();

				//生成したオブジェクトの初期化
				mHideEasingCube[0].mPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mAlpha = 1.0f;
				mHideEasingCube[0].mEndAlpha = 0.0f;

				mHideEasingCube[0].mColor = ColorA(
					color, mHideEasingCube[0].mAlpha);
			}
			//一度のみ初期化

			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				//α値計算
				if ((int)mHideEasingCube.size() > 0) {
					mHideEasingCube[0].mColor.a =
						mHideEasingCube[0].mAlpha;

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mAlpha,
							mHideEasingCube[0].mEndAlpha.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
					if (mHideEasingCube[0].mColor.a <= 0.0f) {

						mHideEasingCube.clear();

						mCanStart = false;
						mIsEnd = true;
					}
				}
			}
		}

	}

}

void FadeIn::circleScalingFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	const float windowOutPos =
		((float)getWindowWidth() / 1.5f);

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CIRCLE_SCALING_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (1.0f / mInterval);

				//必要な個数生成
				mHideCircle.emplace_back();

				//生成したオブジェクトの初期化
				mHideCircle[0].mPos = Vec3f::zero();

				mHideCircle[0].mSize = windowOutPos;

				mHideCircle[0].mColor = ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCircle.emplace_back();

				mHideEasingCircle[0].mPos = Vec2f::zero();

				mHideEasingCircle[0].mSize = windowOutPos;
				mHideEasingCircle[0].mEndSize = 0.0f;

				mHideEasingCircle[0].mAlpha = 1.0f;
				mHideEasingCircle[0].mEndAlpha = 0.0f;

				mHideEasingCircle[0].mColor = ColorA(
					color, mHideEasingCircle[0].mAlpha);
			}
			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if (!isUseEasing) {
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

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

				}
			}
			if (isUseEasing) {
				if ((int)mHideEasingCircle.size() > 0) {
					mHideEasingCircle[0].mColor.a =
						mHideEasingCircle[0].mAlpha;

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCircle[0].mAlpha,
							mHideEasingCircle[0].mEndAlpha.value(),
							(float)time, easeOutInCirc);
						timeline().apply(
							&mHideEasingCircle[0].mSize,
							mHideEasingCircle[0].mEndSize.value(),
							(float)time, easeOutInCirc);

						mIsEndEasing = true;
					}

					//α値が最大値(1.0f)になったら
					//fadeInを使用可能に変更
					if (mHideEasingCircle[0].mColor.a <= 0.0f ||
						mHideEasingCircle[0].mSize <= 0.0f) {

						mHideEasingCircle.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

				}
			}

		}

	}

}

void FadeIn::veilDownFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = VEIL_FADE;

			if (!isUseEasing) {
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
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos = Vec2f::zero();
				mHideEasingCube[0].mEndPos =
					Vec2f(0.0f, -(float)getWindowHeight());

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor = ColorA(color, 1.0f);
			}
			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				if ((int)mHideEasingCube.size() > 0) {

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mPos,
							mHideEasingCube[0].mEndPos.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					if (mHideEasingCube[0].mPos.value().y <=
						-(float)getWindowHeight()) {

						mHideEasingCube.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

				}
			}

		}

	}

}

void FadeIn::fromLeftCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_LEFT_CURTAIN_FADE;

			if (!isUseEasing) {
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
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos = Vec2f::zero();
				mHideEasingCube[0].mEndPos =
					Vec2f(-(float)getWindowWidth(), 0.0f);

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor = ColorA(color, 1.0f);

			}
			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				if ((int)mHideEasingCube.size() > 0) {

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mPos,
							mHideEasingCube[0].mEndPos.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					if (mHideEasingCube[0].mPos.value().x <=
						-(float)getWindowWidth()) {

						mHideEasingCube.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

				}
			}

		}

	}

}

void FadeIn::fromRightCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = FROM_RIGHT_CURTAIN_FADE;

			if (!isUseEasing) {
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
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos = Vec2f::zero();
				mHideEasingCube[0].mEndPos =
					Vec2f((float)getWindowWidth(), 0.0f);

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor =
					ColorA(color, 1.0f);

			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				if ((int)mHideEasingCube.size() > 0) {

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mPos,
							mHideEasingCube[0].mEndPos.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					if (mHideEasingCube[0].mPos.value().x >=
						(float)getWindowWidth()) {

						mHideEasingCube.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

				}
			}

		}

	}

}

void FadeIn::centerCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mCanStart) {

		//生成・初期化
		if (!mIsEndInit) {

			//データをパターンに合わせて初期化
			mPattern = CENTER_CURTAIN_FADE;

			if (!isUseEasing) {
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
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();
				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos =
					Vec2f(-(quarterWindowSize), 0.0f);
				mHideEasingCube[1].mPos =
					Vec2f((quarterWindowSize), 0.0f);

				mHideEasingCube[0].mEndPos =
					Vec2f(-(quarterWindowSize * 3), 0.0f);
				mHideEasingCube[1].mEndPos =
					Vec2f((quarterWindowSize * 3), 0.0f);

				for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
					mHideEasingCube[i].mSize = Vec2f(
						(float)getWindowWidth() / 2,
						(float)getWindowHeight());

					mHideEasingCube[i].mColor = ColorA(color, 1.0f);
				}
			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				if ((int)mHideEasingCube.size() > 0) {

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCube[0].mPos,
							mHideEasingCube[0].mEndPos.value(),
							(float)time, easeOutInCirc);
						timeline().apply(
							&mHideEasingCube[1].mPos,
							mHideEasingCube[1].mEndPos.value(),
							(float)time, easeOutInCirc);

						mIsEndEasing = true;
					}

					if (mHideEasingCube[0].mPos.value().x <=
						-(quarterWindowSize * 3)
						||
						mHideEasingCube[1].mPos.value().x >=
						(quarterWindowSize * 3)) {

						mHideEasingCube.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}
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
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
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

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (((float)getWindowWidth() - space) / mInterval);

				//必要な個数生成
				mHideCylinder.emplace_back();

				//生成したオブジェクトの初期化
				mHideCylinder[0].mStartPos = space;
				mHideCylinder[0].mEndPos = windowOutPos;
				mHideCylinder[0].mSliceCount = slices;
				mHideCylinder[0].mColor = ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCylinder.emplace_back();

				mHideEasingCylinder[0].mStartPos = space;
				mHideEasingCylinder[0].mEndStartPos = windowOutPos;
				mHideEasingCylinder[0].mEndPos = windowOutPos;
				mHideEasingCylinder[0].mSliceCount = slices;
				mHideEasingCylinder[0].mColor = ColorA(color, 1.0f);
			}

			//一度だけしか処理しないように
			mIsEndInit = true;
		}

		//初期化が終了後、更新開始
		if (mIsEndInit) {

			if (!isUseEasing) {
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
			if (isUseEasing) {
				if ((int)mHideEasingCylinder.size() > 0) {

					if (!mIsEndEasing) {
						timeline().apply(
							&mHideEasingCylinder[0].mStartPos,
							mHideEasingCylinder[0].mEndStartPos.value(),
							(float)time, easeOutInCirc);
						mIsEndEasing = true;
					}

					if (mHideEasingCylinder[0].mStartPos >= windowOutPos) {

						mHideEasingCylinder.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}

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
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(Vec3f(mHideEasingCube[i].mPos, 0),
					Vec3f(mHideEasingCube[i].mSize, 0));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case CIRCLE_SCALING_FADE:
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCircle.size(); ++i) {
				gl::color(mHideCircle[i].mColor);
				gl::drawSolidCircle(
					mHideCircle[i].mPos.xy(), mHideCircle[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCircle.size(); ++i) {
				gl::color(mHideEasingCircle[i].mColor);
				gl::drawSolidCircle(
					mHideEasingCircle[i].mPos,
					mHideEasingCircle[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case VEIL_FADE:
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(
					Vec3f(mHideEasingCube[i].mPos, 0.0f),
					Vec3f(mHideEasingCube[i].mSize, 0.0f));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case FROM_LEFT_CURTAIN_FADE:
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(
					Vec3f(mHideEasingCube[i].mPos, 0.0f),
					Vec3f(mHideEasingCube[i].mSize, 0.0f));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case FROM_RIGHT_CURTAIN_FADE:
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(
					Vec3f(mHideEasingCube[i].mPos, 0.0f),
					Vec3f(mHideEasingCube[i].mSize, 0.0f));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case CENTER_CURTAIN_FADE:
		if (!mIsUseEasing) {
			for (unsigned int i = 0; i < mHideCube.size(); ++i) {
				gl::color(mHideCube[i].mColor);
				gl::drawCube(mHideCube[i].mPos, mHideCube[i].mSize);
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
				gl::color(mHideEasingCube[i].mColor);
				gl::drawCube(
					Vec3f(mHideEasingCube[i].mPos, 0.0f),
					Vec3f(mHideEasingCube[i].mSize, 0.0f));
				gl::color(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		break;

	case PIN_HOLE_FADE:
		if (!mIsUseEasing) {
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
		}
		if (mIsUseEasing) {
			for (unsigned int i = 0; i < mHideEasingCylinder.size(); ++i) {
				gl::rotate(Vec3f(90, 0, 0));
				gl::color(mHideEasingCylinder[i].mColor);
				gl::drawCylinder(
					mHideEasingCylinder[i].mStartPos,
					mHideEasingCylinder[i].mEndPos,
					0.1f,
					mHideEasingCylinder[i].mSliceCount);
				gl::color(Color(1, 1, 1));
			}
		}
		break;
	}

	gl::disableAlphaBlending();
	gl::popModelView();

}

