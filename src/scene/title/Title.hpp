
#pragma once

#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"

class Title : public Scene
{
  
public:
  
  Title();
  ~Title();
  
  void update();
  void draw();
  
private:
  
  int mSphereMotion; // ボール微動
  float mDeviceWindowHeight, mDeviceWindowWidth; // デバイスウィンドサイズ
  
  ci::Rectf mFeatherBookRect;
  ci::Rectf mTraceRect;
  
  ci::Rectf mKanaLetterTaRect;
  ci::Rectf mKanaLetterMaRect;
  ci::Rectf mKanaLetterKoRect;
  ci::Rectf mKanaLetterRoRect;
  
  ci::Rectf mSphereBlueRect;
  ci::Rectf mSphereGreenRect;
  ci::Rectf mSphereRedRect;
  
  ci::Rectf mLogoRect;
  ci::Rectf mTapToStartEngRect;
  
};
