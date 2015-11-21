
#pragma once

#include "../Scene.hpp"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

class Title : public Scene
{
private:
  
public:
  Title();
  
  void update();
  void draw();
  
  float mSphere_Motion; // ボール微動
  
  // 背景
  ci::gl::Texture mTitleBack;
  
  // 本とペン
  ci::gl::Texture mFeatherBook;
  ci::Rectf mFeatherBook_Rect;
  // スカーフみたいなやつ
  ci::gl::Texture mTrace;
  ci::Rectf mTrace_Rect;
  
  // 文字「た」
  ci::gl::Texture mKanaLetterTa;
  ci::Rectf mKanaLetterTa_Rect;
  // 文字「ま」
  ci::gl::Texture mKanaLetterMa;
  ci::Rectf mKanaLetterMa_Rect;
  // 文字「こ」
  ci::gl::Texture mKanaLetterKo;
  ci::Rectf mKanaLetterKo_Rect;
  // 文字「ろ」
  ci::gl::Texture mKanaLetterRo;
  ci::Rectf mKanaLetterRo_Rect;
  
  // ボール青
  ci::gl::Texture mSphereBlue;
  ci::Rectf mSphereBlue_Rect;
  // ボール緑
  ci::gl::Texture mSphereGreen;
  ci::Rectf mSphereGreen_Rect;
  // ボール赤
  ci::gl::Texture mSphereRed;
  ci::Rectf mSphereRed_Rect;
  
  // 文字「TAMACORO」
  ci::gl::Texture mLogo;
  ci::Rectf mLogo_Rect;
  // 文字「タッチしてスタート！」
  ci::gl::Texture mTapToStartEng;
  ci::Rectf mTapToStartEng_Rect;
  
};
