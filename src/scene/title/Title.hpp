
#pragma once

#include "../Scene.hpp"
//#include "cinder/ImageIo.h"
//#include "cinder/gl/Texture.h"
#include "../../resource/ResourceManager.hpp"

class Title : public Scene
{
  
public:
  
  Title();
  
  void update();
  void draw();
  
private:
  
  int mSphereMotion; // ボール微動
  
  //// 背景
  //ci::gl::Texture mTitleBack;
  //
  //// 本とペン
  //ci::gl::Texture mFeatherBook;
  ci::Rectf mFeatherBookRect;
  // スカーフみたいなやつ
  //ci::gl::Texture mTrace;
  ci::Rectf mTraceRect;
  
  // 文字「た」
  //ci::gl::Texture mKanaLetterTa;
  ci::Rectf mKanaLetterTaRect;
  // 文字「ま」
  //ci::gl::Texture mKanaLetterMa;
  ci::Rectf mKanaLetterMaRect;
  // 文字「こ」
  //ci::gl::Texture mKanaLetterKo;
  ci::Rectf mKanaLetterKoRect;
  // 文字「ろ」
  //ci::gl::Texture mKanaLetterRo;
  ci::Rectf mKanaLetterRoRect;
  
  // ボール青
  //ci::gl::Texture mSphereBlue;
  ci::Rectf mSphereBlueRect;
  // ボール緑
  //ci::gl::Texture mSphereGreen;
  ci::Rectf mSphereGreenRect;
  // ボール赤
  //ci::gl::Texture mSphereRed;
  ci::Rectf mSphereRedRect;
  
  // 文字「TAMACORO」
  //ci::gl::Texture mLogo;
  ci::Rectf mLogoRect;
  // 文字「タッチしてスタート！」
  //ci::gl::Texture mTapToStartEng;
  ci::Rectf mTapToStartEngRect;
  
};
