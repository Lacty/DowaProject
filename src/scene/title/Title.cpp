
#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>

Title::Title()
{
  //Load Textures
  dowa::ResourceManager::texture().insert("background/title/TitleBack.jpg", TextureKey::TitleBack);
  dowa::ResourceManager::texture().insert("background/title/FeatherBookResize.png", TextureKey::FeatherBook);
  dowa::ResourceManager::texture().insert("background/title/Logo.png", TextureKey::Logo);
  dowa::ResourceManager::texture().insert("background/title/TapToStartEng.png", TextureKey::TapToStartEng);
  dowa::ResourceManager::texture().insert("background/title/Trace.png", TextureKey::Trace);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterTa.png", TextureKey::LetterTa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterMa.png", TextureKey::LetterMa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterKo.png", TextureKey::LetterKo);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterRo.png", TextureKey::LetterRo);
  dowa::ResourceManager::texture().insert("background/title/SphereBlue.png", TextureKey::SphereBlue);
  dowa::ResourceManager::texture().insert("background/title/SphereGreen.png", TextureKey::SphereGreen);
  dowa::ResourceManager::texture().insert("background/title/SphereRed.png", TextureKey::SphereRed);

  // 背景
  //mTitleBack = (loadImage(cinder::app::loadAsset("background/title/TitleBack.jpg")));

  // 本とペン 「描画する画像が大きすぎてちっちゃく描画したときにジャギが発生していた為、元画像を 912 × 768 にリサイズ」
  //mFeatherBook = (loadImage(cinder::app::loadAsset("background/title/FeatherBook.png")));
  mFeatherBookRect = ci::Rectf(150, 15, 430, 250); // size = 280, 235
  // スカーフみたいなやつ
  //mTrace = (loadImage(cinder::app::loadAsset("background/title/Trace.png")));
  mTraceRect = ci::Rectf(120, 50, 340, 245); // size = 220, 195


  // 文字「た」
  //mKanaLetterTa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterTa.png")));
  mKanaLetterTaRect = ci::Rectf(130, 80, 220, 170); // size = 90, 90
  // 文字「ま」
  //mKanaLetterMa = (loadImage(cinder::app::loadAsset("background/title/KanaLetterMa.png")));
  mKanaLetterMaRect = ci::Rectf(210, 15, 300, 105); // size = 90, 90
  // 文字「こ」
  //mKanaLetterKo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterKo.png")));
  mKanaLetterKoRect = ci::Rectf(260, 100, 350, 190); // size = 90, 90
  // 文字「ろ」
  //mKanaLetterRo = (loadImage(cinder::app::loadAsset("background/title/KanaLetterRo.png")));
  mKanaLetterRoRect = ci::Rectf(350, 40, 440, 130); // size = 90, 90


  // ボール青
  //mSphereBlue = (loadImage(cinder::app::loadAsset("background/title/SphereBlue.png")));
  mSphereBlueRect = ci::Rectf(320, 25, 360, 65); // size = 40, 40
  // ボール緑
  //mSphereGreen = (loadImage(cinder::app::loadAsset("background/title/SphereGreen.png")));
  mSphereGreenRect = ci::Rectf(130, 165, 180, 215); // size = 50, 50
  // ボール赤
  //mSphereRed = (loadImage(cinder::app::loadAsset("background/title/SphereRed.png")));
  mSphereRedRect = ci::Rectf(350, 173, 420, 243); // size = 70, 70


  // 文字「TAMACORO」
  //mLogo = (loadImage(cinder::app::loadAsset("background/title/Logo.png")));
  mLogoRect = ci::Rectf(190, 200, 280, 220); // size = 90, 20
  // 文字「タッチしてスタート！」
  //mTapToStartEng = (loadImage(cinder::app::loadAsset("background/title/TapToStartEng.png")));
  mTapToStartEngRect = ci::Rectf(180, 265, 400, 295); // size = 220, 30

}

void Title::update()
{

  mSphereMotion++;


  mKanaLetterTaRect = ci::Rectf(130, 80 + sin(M_PI * 2 / 240 * mSphereMotion) * 2,
    220, 170 + sin(M_PI * 2 / 240 * mSphereMotion) * 2);

  mKanaLetterMaRect = ci::Rectf(210, 15 + sin(M_PI * 2 / 240 * mSphereMotion) * 4,
    300, 105 + sin(M_PI * 2 / 240 * mSphereMotion) * 4);

  mKanaLetterKoRect = ci::Rectf(260, 100 + sin(M_PI * 2 / 240 * mSphereMotion) * -2,
    350, 190 + sin(M_PI * 2 / 240 * mSphereMotion) * -2);

  mKanaLetterRoRect = ci::Rectf(350, 40 + sin(M_PI * 2 / 240 * mSphereMotion) * -3,
    440, 130 + sin(M_PI * 2 / 240 * mSphereMotion) * -3);

  mSphereBlueRect = ci::Rectf(320, 25 + sin(M_PI * 2 / 240 * mSphereMotion) * 10,
    360, 65 + sin(M_PI * 2 / 240 * mSphereMotion) * 10);

  mSphereGreenRect = ci::Rectf(130, 165 + sin(M_PI * 2 / 240 * mSphereMotion) * -3,
    180, 215 + sin(M_PI * 2 / 240 * mSphereMotion) * -3);

  mSphereRedRect = ci::Rectf(350, 173 + sin(M_PI * 2 / 240 * mSphereMotion) * 7,
    420, 243 + sin(M_PI * 2 / 240 * mSphereMotion) * 7);
}

void Title::draw()
{

  Title::update();

  ci::gl::pushModelView();

  ci::gl::clear();
  cinder::gl::enableAlphaBlending(true); // αチャンネル有効

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::TitleBack), ci::app::getWindowBounds());
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::FeatherBook), mFeatherBookRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Trace), mTraceRect);

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterTa), mKanaLetterTaRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterMa), mKanaLetterMaRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterKo), mKanaLetterKoRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterRo), mKanaLetterRoRect);

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereBlue), mSphereBlueRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereGreen), mSphereGreenRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereRed), mSphereRedRect);

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Logo), mLogoRect);
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::TapToStartEng), mTapToStartEngRect);

  ci::gl::popModelView();
}
