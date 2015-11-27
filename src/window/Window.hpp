
#pragma once
#include "cinder/app/App.h"


namespace dowa {

inline int getWindowWidth() { return ci::app::getWindowHeight(); }
inline int getWindowHeight() { return ci::app::getWindowWidth(); }

inline ci::Vec2i getWindowSize() { return ci::Vec2i(getWindowWidth(), getWindowHeight()); }
inline ci::Vec2f getWindowCenter() { return getWindowSize() * 0.5; }

inline float getWindowAspectRatio() { return getWindowWidth() / (float)getWindowHeight(); }

inline float getFrameRate() { return ci::app::getFrameRate(); }
inline void  setFrameRate(float frameRate) { ci::app::setFrameRate(frameRate); }

} // namespace dowa