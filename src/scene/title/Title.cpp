

/*
 
 iPad画面サイズ 768 × 1024
 iPhone画面サイズ 320 × 568
 注意！横画面にしてもxとyの座標は変わらない可能性あり
 どうしてもうまくいかない場合はxとyを逆にしてみること
 ビルドするときの注意事項 Deployment Info -> Device Orientation
 Landscape Left,Landscape Right にチェックを入れること、それ以外はチェックを外す
 
 */

#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include <math.h>
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

Title::Title()
{
  
  // デバイスのウィンドサイズを取得し、代入
  mDeviceWindowHeight = ci::app::getWindowHeight();
  mDeviceWindowWidth = ci::app::getWindowWidth();
  
  // 画像読み込み
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
  
  
  // 画像座標設定
  mFeatherBookRect = ci::Rectf(mDeviceWindowHeight / 5,  mDeviceWindowWidth / 20,
                               mDeviceWindowHeight / 1.2, mDeviceWindowWidth / 1.28); // 本とペン
  
  mTraceRect = ci::Rectf(mDeviceWindowHeight / 4.7, mDeviceWindowWidth / 6.5,
                         mDeviceWindowHeight / 1.5, mDeviceWindowWidth / 1.3); // 羽
  
  mLogoRect = ci::Rectf(mDeviceWindowHeight / 3.5, mDeviceWindowWidth / 1.6,
                        mDeviceWindowHeight / 2, mDeviceWindowWidth / 1.45); // TAMACORO
  
  mTapToStartEngRect = ci::Rectf(mDeviceWindowHeight / 3.3, mDeviceWindowWidth / 1.22,
                                 mDeviceWindowHeight / 1.35, mDeviceWindowWidth / 1.12); // タッチしてスタート！
}

void Title::update()
{
  
  if(dowa::Device::isTouchBegan()) // タッチされたらシーン切り替え
  {
    SceneManager::create(SceneType::Result); // とりあえずリザルトに切り替え
  }

  mSphereMotion++;


  mKanaLetterTaRect = ci::Rectf(mDeviceWindowHeight / 4.5,
                                mDeviceWindowWidth / 4 + sin(M_PI * 2 / 240 * mSphereMotion) * 2,
                                mDeviceWindowHeight / 2.5,
                                mDeviceWindowWidth / 2 + sin(M_PI * 2 / 240 * mSphereMotion) * 2); // た
  
  mKanaLetterMaRect = ci::Rectf(mDeviceWindowHeight / 2.7,
                                mDeviceWindowWidth / 10 + sin(M_PI * 2 / 240 * mSphereMotion) * -2,
                                mDeviceWindowHeight / 1.77,
                                mDeviceWindowWidth / 3 + sin(M_PI * 2 / 240 * mSphereMotion) * -2); // ま

  mKanaLetterKoRect = ci::Rectf(mDeviceWindowHeight / 2.1,
                                mDeviceWindowWidth / 3.1 + sin(M_PI * 2 / 240 * mSphereMotion) * 3,
                                mDeviceWindowHeight / 1.5,
                                mDeviceWindowWidth / 1.8 + sin(M_PI * 2 / 240 * mSphereMotion) * 3); // こ

  mKanaLetterRoRect = ci::Rectf(mDeviceWindowHeight / 1.6,
                                mDeviceWindowWidth / 6 + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5,
                                mDeviceWindowHeight / 1.22,
                                mDeviceWindowWidth / 2.5 + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5); // ろ
  
  mSphereBlueRect = ci::Rectf(mDeviceWindowHeight / 1.8,
                              mDeviceWindowWidth / 7.9 + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5,
                              mDeviceWindowHeight / 1.55,
                              mDeviceWindowWidth / 4.1 + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5); // 青
  
  mSphereGreenRect = ci::Rectf(mDeviceWindowHeight / 5.8,
                               mDeviceWindowWidth / 2.0 + sin(M_PI * 2 / 240 * mSphereMotion) * -1.5,
                               mDeviceWindowHeight / 3.28,
                               mDeviceWindowWidth / 1.5 + sin(M_PI * 2 / 240 * mSphereMotion) * -1.5); // 緑
  
  mSphereRedRect = ci::Rectf(mDeviceWindowHeight / 1.6,
                             mDeviceWindowWidth / 1.8 + sin(M_PI * 2 / 240 * mSphereMotion) * -2.5,
                             mDeviceWindowHeight / 1.27,
                             mDeviceWindowWidth  / 1.3 + sin(M_PI * 2 / 240 * mSphereMotion) * -2.5); // 赤
  
}

void Title::draw()
{

  ci::gl::pushModelView();

  ci::gl::clear();
  
  cinder::gl::enableAlphaBlending(true); // αチャンネル有効

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::TitleBack), ci::app::getWindowBounds()); // 背景
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::FeatherBook), mFeatherBookRect); // 本とペン
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Trace), mTraceRect); // 羽

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterTa), mKanaLetterTaRect); // た
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterMa), mKanaLetterMaRect); // ま
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterKo), mKanaLetterKoRect); // こ
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::LetterRo), mKanaLetterRoRect); // ろ

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereBlue), mSphereBlueRect); // 青
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereGreen), mSphereGreenRect); // 緑
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::SphereRed), mSphereRedRect); // 赤

  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::Logo), mLogoRect); // TAMACORO
  ci::gl::draw(dowa::ResourceManager::texture().get(TextureKey::TapToStartEng), mTapToStartEngRect); // タッチしてスタート！
  
  cinder::gl::enableAlphaBlending(false); // αチャンネル無効
    
  ci::gl::popModelView();
  
}
