
#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>

Title::Title()
{
  // 背景
  mTitleBack = (loadImage(cinder::app::loadAsset("background/title/TitleBack.jpg")));
  
  // 本とペン 「描画する画像が大きすぎてちっちゃく描画したときにジャギが発生していた為、元画像を 912 × 768 にリサイズ」
  mFeatherBook = (loadImage(cinder::app::loadAsset("background/title/FeatherBook.png")));
  mFeatherBook_Rect = ci::Rectf(150, 15, 430, 250); // size = 280, 235
  // スカーフみたいなやつ
  mTrace = (loadImage(cinder::app::loadAsset("background/title/Trace.png")));
  mTrace_Rect = ci::Rectf( 120, 50, 340, 245); // size = 220, 195
  
  
  // 文字「た」
  mKanaLetterTa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterTa.png")));
  mKanaLetterTa_Rect = ci::Rectf( 130, 80, 220, 170); // size = 90, 90
  // 文字「ま」
  mKanaLetterMa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterMa.png")));
  mKanaLetterMa_Rect = ci::Rectf( 210, 15, 300, 105); // size = 90, 90
  // 文字「こ」
  mKanaLetterKo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterKo.png")));
  mKanaLetterKo_Rect = ci::Rectf( 260, 100, 350, 190); // size = 90, 90
  // 文字「ろ」
  mKanaLetterRo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterRo.png")));
  mKanaLetterRo_Rect = ci::Rectf( 350, 40, 440, 130); // size = 90, 90

  
  // ボール青
  mSphereBlue = (loadImage(cinder::app::loadAsset("background/title/SphereBlue.png")));
  mSphereBlue_Rect = ci::Rectf( 320, 25, 360, 65); // size = 40, 40
  // ボール緑
  mSphereGreen = (loadImage(cinder::app::loadAsset("background/title/SphereGreen.png")));
  mSphereGreen_Rect = ci::Rectf( 130, 165, 180, 215); // size = 50, 50
  // ボール赤
  mSphereRed = (loadImage(cinder::app::loadAsset("background/title/SphereRed.png")));
  mSphereRed_Rect = ci::Rectf( 350, 173, 420, 243); // size = 70, 70
  
  
  // 文字「TAMACORO」
  mLogo = (loadImage(cinder::app::loadAsset("background/title/Logo.png")));
  mLogo_Rect = ci::Rectf( 190, 200, 280, 220); // size = 90, 20
  // 文字「タッチしてスタート！」
  mTapToStartEng = (loadImage(cinder::app::loadAsset("background/title/TapToStartEng.png")));
  mTapToStartEng_Rect = ci::Rectf( 180, 265, 400, 295); // size = 220, 30
  
}

void Title::update()
{
  mKanaLetterTa_Rect = ci::Rectf( 130, 80 + sin(M_PI * 2 / 240 * mSphere_Motion) * 2,
                                 220, 170 + sin(M_PI * 2 / 240 * mSphere_Motion) * 2);
  
  mKanaLetterMa_Rect = ci::Rectf( 210, 15 + sin(M_PI * 2 / 240 * mSphere_Motion) * 4,
                                  300, 105 + sin(M_PI * 2 / 240 * mSphere_Motion) * 4);
  
  mKanaLetterKo_Rect = ci::Rectf( 260, 100 + sin(M_PI * 2 / 240 * mSphere_Motion) * -2,
                                  350, 190 + sin(M_PI * 2 / 240 * mSphere_Motion) * -2);
  
  mKanaLetterRo_Rect = ci::Rectf( 350, 40 + sin(M_PI * 2 / 240 * mSphere_Motion) * -3,
                                  440, 130 + sin(M_PI * 2 / 240 * mSphere_Motion) * -3);
  
  mSphereBlue_Rect = ci::Rectf( 320, 25 + sin(M_PI * 2 / 240 * mSphere_Motion) * 10,
                                360, 65 + sin(M_PI * 2 / 240 * mSphere_Motion) * 10);
  
  mSphereGreen_Rect = ci::Rectf( 130, 165 + sin(M_PI * 2 / 240 * mSphere_Motion) * -3,
                                 180, 215 + sin(M_PI * 2 / 240 * mSphere_Motion) * -3);
  
  mSphereRed_Rect = ci::Rectf( 350, 173 + sin(M_PI * 2 / 240 * mSphere_Motion) * 7,
                               420, 243 + sin(M_PI * 2 / 240 * mSphere_Motion) * 7);
  
  mSphere_Motion++;
}

void Title::draw()
{
  ci::gl::pushModelView();
  
  Title::update();
  
  ci::gl::clear();
  cinder::gl::enableAlphaBlending(true); // αチャンネル有効
  
  ci::gl::draw( mTitleBack, ci::app::getWindowBounds());
  ci::gl::draw( mFeatherBook, mFeatherBook_Rect);
  ci::gl::draw( mTrace, mTrace_Rect);
  
  ci::gl::draw( mKanaLetterTa, mKanaLetterTa_Rect);
  ci::gl::draw( mKanaLetterMa, mKanaLetterMa_Rect);
  ci::gl::draw( mKanaLetterKo, mKanaLetterKo_Rect);
  ci::gl::draw( mKanaLetterRo, mKanaLetterRo_Rect);
  
  ci::gl::draw( mSphereBlue, mSphereBlue_Rect);
  ci::gl::draw( mSphereGreen, mSphereGreen_Rect);
  ci::gl::draw( mSphereRed, mSphereRed_Rect);
  
  ci::gl::draw( mLogo, mLogo_Rect);
  ci::gl::draw( mTapToStartEng, mTapToStartEng_Rect);
  
  ci::gl::popModelView();
}
