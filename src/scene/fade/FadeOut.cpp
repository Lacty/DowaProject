
#include "FadeOut.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;


FadeOut::FadeOut() {
	mPattern = FULL_SCREEN_FADE;

	mCanStart =
		mIsEnd =
		mIsEndInit =
		mIsEndEasing = false;
}

bool FadeOut::getIsEnd() {
	return mIsEnd;
}

//---------------------------------------------

void FadeOut::setType(FadeType type,
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
//TODO:Easing‚ðŽg‚Á‚½’†g‚ÌŽÀ‘•
//---------------------------------------------------

void FadeOut::fullScreenFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = FULL_SCREEN_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (1.0f / mInterval);

				mHideCube.emplace_back();

				mHideCube[0].mPos = Vec3f::zero();

				mHideCube[0].mSize = Vec3f(
					(float)getWindowWidth(),
					(float)getWindowHeight(),
					0);

				mHideCube[0].mColor = ColorA(color, 0.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mAlpha = 0.0f;
				mHideEasingCube[0].mEndAlpha = 1.0f;

				mHideEasingCube[0].mColor = ColorA(
					color, mHideEasingCube[0].mAlpha);
			}

			mIsEndInit = true;
		}
		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mColor.a += mSpeed;

					if (mHideCube[0].mColor.a >= 1.0f) {

						mHideCube.clear();

						mCanStart = false;
						mIsEnd = true;
					}
				}
			}
			if (isUseEasing) {
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

					if (mHideEasingCube[0].mColor.a >= 1.0f) {

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

void FadeOut::circleScalingFade(int time, Color color, bool isUseEasing) {

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

		if (!mIsEndInit) {

			mPattern = CIRCLE_SCALING_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (1.0f / mInterval);

				mHideCircle.emplace_back();

				mHideCircle[0].mPos = Vec3f::zero();
				mHideCircle[0].mSize = 0.0f;
				mHideCircle[0].mColor = ColorA(color, 0.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCircle.emplace_back();

				mHideEasingCircle[0].mPos = Vec2f::zero();

				mHideEasingCircle[0].mSize = 0.0f;
				mHideEasingCircle[0].mEndSize = windowOutPos;

				mHideEasingCircle[0].mAlpha = 0.0f;
				mHideEasingCircle[0].mEndAlpha = 1.0f;

				mHideEasingCircle[0].mColor = ColorA(
					color, mHideEasingCircle[0].mAlpha);
			}

			mIsEndInit = true;
		}
		if (mIsEndInit) {

			const float sizeChangeSpeed =
				((float)getWindowWidth() / mInterval);

			if (!isUseEasing) {
				if ((int)mHideCircle.size() > 0) {
					mHideCircle[0].mColor.a += mSpeed;
					mHideCircle[0].mSize += sizeChangeSpeed;

					if (mHideCircle[0].mColor.a >= 1.0f ||
						mHideCircle[0].mSize >= windowOutPos) {

						mHideCircle.clear();

						mCanStart = false;
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

					if (mHideEasingCircle[0].mColor.a >= 1.0f ||
						mHideEasingCircle[0].mSize >= windowOutPos) {

						mHideCircle.clear();

						mCanStart =
							mIsUseEasing = false;
						mIsEnd = true;
					}
				}
			}

		}
	}

}

void FadeOut::veilDownFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = VEIL_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = ((float)getWindowHeight() / mInterval);

				mHideCube.emplace_back();

				mHideCube[0].mPos =
					Vec3f(0.0f, -(float)getWindowHeight(), 0.0f);

				mHideCube[0].mSize = Vec3f(
					(float)getWindowWidth(),
					(float)getWindowHeight(),
					0.1f);

				mHideCube[0].mColor = ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos =
					Vec2f(0.0f, -(float)getWindowHeight());
				mHideEasingCube[0].mEndPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor = ColorA(color, 1.0f);
			}

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mPos.y += mSpeed;

					if (mHideCube[0].mPos.y >= 0.0f) {

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

					if (mHideEasingCube[0].mPos.value().y >= 0.0f) {

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

void FadeOut::fromLeftCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = FROM_LEFT_CURTAIN_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = ((float)getWindowWidth() / mInterval);

				mHideCube.emplace_back();

				mHideCube[0].mPos =
					Vec3f(-(float)getWindowWidth(), 0.0f, 0.0f);

				mHideCube[0].mSize = Vec3f(
					(float)getWindowWidth(),
					(float)getWindowHeight(),
					0.1f);

				mHideCube[0].mColor = ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos =
					Vec2f(-(float)getWindowWidth(), 0.0f);
				mHideEasingCube[0].mEndPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor = ColorA(color, 1.0f);

			}

			mIsEndInit = true;
		}
		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mPos.x += mSpeed;

					if (mHideCube[0].mPos.x >= 0.0f) {

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

					if (mHideEasingCube[0].mPos.value().x >= 0.0f) {

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

void FadeOut::fromRightCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = FROM_RIGHT_CURTAIN_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = ((float)getWindowWidth() / mInterval);

				mHideCube.emplace_back();

				mHideCube[0].mPos =
					Vec3f((float)getWindowWidth(), 0.0f, 0.0f);

				mHideCube[0].mSize = Vec3f(
					(float)getWindowWidth(),
					(float)getWindowHeight(),
					0.1f);

				mHideCube[0].mColor =
					ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCube.emplace_back();

				mHideEasingCube[0].mPos =
					Vec2f((float)getWindowWidth(), 0.0f);
				mHideEasingCube[0].mEndPos = Vec2f::zero();

				mHideEasingCube[0].mSize = Vec2f(
					(float)getWindowWidth(),
					(float)getWindowHeight());

				mHideEasingCube[0].mColor =
					ColorA(color, 1.0f);

			}
			mIsEndInit = true;
		}

		if (mIsEndInit) {
			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mPos.x -= mSpeed;

					if (mHideCube[0].mPos.x <= 0.0f) {

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

					if (mHideEasingCube[0].mPos.value().x <= 0.0f) {

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

void FadeOut::centerCurtainFade(int time, Color color, bool isUseEasing) {

	if (!mCanStart) {
		mCanStart = true;
		mIsEnd =
			mIsEndInit =
			mIsUseEasing =
			mIsEndEasing = false;
	}

	const float quarterWindowSize = (float)(getWindowWidth() / 4);

	if (mCanStart) {

		if (!mIsEndInit) {

			mPattern = CENTER_CURTAIN_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed =
					((float)(getWindowWidth() / 2) / mInterval);

				mHideCube.emplace_back();
				mHideCube.emplace_back();

				mHideCube[0].mPos =
					Vec3f(-(quarterWindowSize * 3), 0.0f, 0.0f);
				mHideCube[1].mPos =
					Vec3f((quarterWindowSize * 3), 0.0f, 0.0f);

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
					Vec2f(-(quarterWindowSize * 3), 0.0f);
				mHideEasingCube[1].mPos =
					Vec2f((quarterWindowSize * 3), 0.0f);

				mHideEasingCube[0].mEndPos =
					Vec2f(-(quarterWindowSize), 0.0f);
				mHideEasingCube[1].mEndPos =
					Vec2f((quarterWindowSize), 0.0f);

				for (unsigned int i = 0; i < mHideEasingCube.size(); ++i) {
					mHideEasingCube[i].mSize = Vec2f(
						(float)getWindowWidth() / 2,
						(float)getWindowHeight());

					mHideEasingCube[i].mColor = ColorA(color, 1.0f);
				}
			}

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCube.size() > 0) {
					mHideCube[0].mPos.x += mSpeed;
					mHideCube[1].mPos.x -= mSpeed;

					if (mHideCube[0].mPos.x >=
						-quarterWindowSize
						||
						mHideCube[1].mPos.x <=
						quarterWindowSize) {

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

					if (mHideEasingCube[0].mPos.value().x >=
						-quarterWindowSize
						||
						mHideEasingCube[1].mPos.value().x <=
						quarterWindowSize) {

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

void FadeOut::pinHoleFade(
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

		if (!mIsEndInit) {

			mPattern = PIN_HOLE_FADE;

			if (!isUseEasing) {
				mInterval = (60 * time);
				mSpeed = (((float)getWindowWidth() - space) / mInterval);

				mHideCylinder.emplace_back();

				mHideCylinder[0].mStartPos = windowOutPos;
				mHideCylinder[0].mEndPos = windowOutPos;
				mHideCylinder[0].mSliceCount = slices;
				mHideCylinder[0].mColor = ColorA(color, 1.0f);
			}
			if (isUseEasing) {
				mIsUseEasing = true;

				mHideEasingCylinder.emplace_back();

				mHideEasingCylinder[0].mStartPos = windowOutPos;
				mHideEasingCylinder[0].mEndStartPos = space;
				mHideEasingCylinder[0].mEndPos = windowOutPos;
				mHideEasingCylinder[0].mSliceCount = slices;
				mHideEasingCylinder[0].mColor = ColorA(color, 1.0f);
			}

			mIsEndInit = true;
		}

		if (mIsEndInit) {

			if (!isUseEasing) {
				if ((int)mHideCylinder.size() > 0) {
					mHideCylinder[0].mStartPos -= mSpeed;

					if (mHideCylinder[0].mStartPos <= space) {

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

					if (mHideEasingCylinder[0].mStartPos <= space) {

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

void FadeOut::draw() {

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
					Vec3f(mHideEasingCube[i].mPos,0.0f), 
					Vec3f(mHideEasingCube[i].mSize,0.0f));
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

