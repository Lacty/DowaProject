
#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>

#define PI 3.141592654f

Title::Title()
{
  // 背景
  MyTitleBack = (loadImage(cinder::app::loadAsset("background/title/TitleBack.jpg")));
  
  // 本とペン 「描画する画像が大きすぎてちっちゃく描画したときにジャギが発生していた為、元画像を 912 × 768 にリサイズ」
  MyFeatherBook = (loadImage(cinder::app::loadAsset("background/title/FeatherBook.png")));
  MyFeatherBook_Rect = ci::Rectf(150, 15, 430, 250); // size = 280, 235
  // スカーフみたいなやつ
  MyTrace = (loadImage(cinder::app::loadAsset("background/title/Trace.png")));
  MyTrace_Rect = ci::Rectf( 120, 50, 340, 245); // size = 220, 195
  
  
  // 文字「た」
  MyKanaLetterTa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterTa.png")));
  MyKanaLetterTa_Rect = ci::Rectf( 130, 80, 220, 170); // size = 90, 90
  // 文字「ま」
  MyKanaLetterMa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterMa.png")));
  MyKanaLetterMa_Rect = ci::Rectf( 210, 15, 300, 105); // size = 90, 90
  // 文字「こ」
  MyKanaLetterKo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterKo.png")));
  MyKanaLetterKo_Rect = ci::Rectf( 260, 100, 350, 190); // size = 90, 90
  // 文字「ろ」
  MyKanaLetterRo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterRo.png")));
  MyKanaLetterRo_Rect = ci::Rectf( 350, 40, 440, 130); // size = 90, 90
  
  
  // test
  MySphere_Motion = 0.0f;
  i = 1;
  

  // ボール青
  MySphereBlue = (loadImage(cinder::app::loadAsset("background/title/SphereBlue.png")));
  MySphereBlue_Rect = ci::Rectf( 320, 25, 360, 65); // size = 40, 40
  // ボール緑
  MySphereGreen = (loadImage(cinder::app::loadAsset("background/title/SphereGreen.png")));
  MySphereGreen_Rect = ci::Rectf( 130, 165, 180, 215); // size = 50, 50
  // ボール赤
  MySphereRed = (loadImage(cinder::app::loadAsset("background/title/SphereRed.png")));
  MySphereRed_Rect = ci::Rectf( 350, 173, 420, 243); // size = 70, 70
  
  
  // 文字「TAMACORO」
  MyLogo = (loadImage(cinder::app::loadAsset("background/title/Logo.png")));
  MyLogo_Rect = ci::Rectf( 190, 200, 280, 220); // size = 90, 20
  // 文字「タッチしてスタート！」
  MyTapToStartEng = (loadImage(cinder::app::loadAsset("background/title/TapToStartEng.png")));
  MyTapToStartEng_Rect = ci::Rectf( 180, 265, 400, 295); // size = 220, 30
  
}

void Title::update()
{
  MyKanaLetterTa_Rect = ci::Rectf( 130, 80 + sin(PI * 2 / 240 * MySphere_Motion) * 2,
                                 220, 170 + sin(PI * 2 / 240 * MySphere_Motion) * 2);
  
  MyKanaLetterMa_Rect = ci::Rectf( 210, 15 + sin(PI * 2 / 240 * MySphere_Motion) * 4,
                                  300, 105 + sin(PI * 2 / 240 * MySphere_Motion) * 4);
  
  MyKanaLetterKo_Rect = ci::Rectf( 260, 100 + sin(PI * 2 / 240 * MySphere_Motion) * -2,
                                  350, 190 + sin(PI * 2 / 240 * MySphere_Motion) * -2);
  
  MyKanaLetterRo_Rect = ci::Rectf( 350, 40 + sin(PI * 2 / 240 * MySphere_Motion) * -3,
                                  440, 130 + sin(PI * 2 / 240 * MySphere_Motion) * -3);
  
  MySphereBlue_Rect = ci::Rectf( 320, 25 + sin(PI * 2 / 240 * MySphere_Motion) * 10,
                                360, 65 + sin(PI * 2 / 240 * MySphere_Motion) * 10);
  
  MySphereGreen_Rect = ci::Rectf( 130, 165 + sin(PI * 2 / 240 * MySphere_Motion) * -3,
                                 180, 215 + sin(PI * 2 / 240 * MySphere_Motion) * -3);
  
  MySphereRed_Rect = ci::Rectf( 350, 173 + sin(PI * 2 / 240 * MySphere_Motion) * 7,
                               420, 243 + sin(PI * 2 / 240 * MySphere_Motion) * 7);
  
  MySphere_Motion++;
}

void Title::draw()
{
  ci::gl::pushModelView();
  
  Title::update();
  
  ci::gl::clear();
  cinder::gl::enableAlphaBlending(true); // αチャンネル有効
  
  ci::gl::draw( MyTitleBack, ci::app::getWindowBounds());
  ci::gl::draw( MyFeatherBook, MyFeatherBook_Rect);
  ci::gl::draw( MyTrace, MyTrace_Rect);
  
  ci::gl::draw( MyKanaLetterTa, MyKanaLetterTa_Rect);
  ci::gl::draw( MyKanaLetterMa, MyKanaLetterMa_Rect);
  ci::gl::draw( MyKanaLetterKo, MyKanaLetterKo_Rect);
  ci::gl::draw( MyKanaLetterRo, MyKanaLetterRo_Rect);
  
  ci::gl::draw( MySphereBlue, MySphereBlue_Rect);
  ci::gl::draw( MySphereGreen, MySphereGreen_Rect);
  ci::gl::draw( MySphereRed, MySphereRed_Rect);
  
  ci::gl::draw( MyLogo, MyLogo_Rect);
  ci::gl::draw( MyTapToStartEng, MyTapToStartEng_Rect);
  
  ci::gl::popModelView();
}
