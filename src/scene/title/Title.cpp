
#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "../../device/Device.hpp"
#include "../../scene/SceneManager.hpp"

Title::Title()
{
  std::cout << "start title" << std::endl;
  std::cout << ci::app::getWindowHeight() << std::endl;

  // デバイスのウィンドサイズを取得し、代入
  mDeviceWindowWidth = ci::app::getWindowWidth();
  mDeviceWindowHeight = ci::app::getWindowHeight();
  
  // 画像読み込み
  /*dowa::ResourceManager::texture().insert("background/title/TitleBack.jpg", TextureKey::TitleBack);
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
  dowa::ResourceManager::texture().insert("background/title/SphereRed.png", TextureKey::SphereRed);*/
  
  
  // 画像座標設定
  mFeatherBookRect = ci::Rectf(mDeviceWindowWidth / 5.0f,  mDeviceWindowHeight / 20.0f,
                               mDeviceWindowWidth / 1.2f, mDeviceWindowHeight / 1.28f); // 本とペン
  
  mTraceRect = ci::Rectf(mDeviceWindowWidth / 4.7f, mDeviceWindowHeight / 6.5f,
                         mDeviceWindowWidth / 1.5f, mDeviceWindowHeight / 1.3f); // 羽
  
  mLogoRect = ci::Rectf(mDeviceWindowWidth / 3.5f, mDeviceWindowHeight / 1.6f,
                        mDeviceWindowWidth / 2.0f, mDeviceWindowHeight / 1.45f); // TAMACORO
  
  mTapToStartEngRect = ci::Rectf(mDeviceWindowWidth / 3.3f, mDeviceWindowHeight / 1.22f,
                                 mDeviceWindowWidth / 1.35f, mDeviceWindowHeight / 1.12f); // タッチしてスタート！
}

Title::~Title() {
  std::cout << "end title" << std::endl;
}

void Title::update()
{
  
  if(dowa::Device::isTouchBegan())
  {
    SceneManager::create(SceneType::SelectLoad);
  }

  mSphereMotion++;


  mKanaLetterTaRect = ci::Rectf(mDeviceWindowWidth / 4.5f,
                                mDeviceWindowHeight / 4.0f + sin(M_PI * 2 / 240 * mSphereMotion) * 2,
                                mDeviceWindowWidth / 2.5f,
                                mDeviceWindowHeight / 2.0f + sin(M_PI * 2 / 240 * mSphereMotion) * 2); // た
  
  mKanaLetterMaRect = ci::Rectf(mDeviceWindowWidth / 2.7f,
                                mDeviceWindowHeight / 10.0f + sin(M_PI * 2 / 240 * mSphereMotion) * -2,
                                mDeviceWindowWidth / 1.77f,
                                mDeviceWindowHeight / 3.0f + sin(M_PI * 2 / 240 * mSphereMotion) * -2); // ま

  mKanaLetterKoRect = ci::Rectf(mDeviceWindowWidth / 2.1f,
                                mDeviceWindowHeight / 3.1f + sin(M_PI * 2 / 240 * mSphereMotion) * 3,
                                mDeviceWindowWidth / 1.5f,
                                mDeviceWindowHeight / 1.8f + sin(M_PI * 2 / 240 * mSphereMotion) * 3); // こ

  mKanaLetterRoRect = ci::Rectf(mDeviceWindowWidth / 1.6f,
                                mDeviceWindowHeight / 6.0f + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5f,
                                mDeviceWindowWidth / 1.22f,
                                mDeviceWindowHeight / 2.5f + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5f); // ろ
  
  mSphereBlueRect = ci::Rectf(mDeviceWindowWidth / 1.8f,
                              mDeviceWindowHeight / 7.9f + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5f,
                              mDeviceWindowWidth / 1.55f,
                              mDeviceWindowHeight / 4.1f + sin(M_PI * 2 / 240 * mSphereMotion) * 1.5f); // 青
  
  mSphereGreenRect = ci::Rectf(mDeviceWindowWidth / 5.8f,
                               mDeviceWindowHeight / 2.0f + sin(M_PI * 2 / 240 * mSphereMotion) * -1.5f,
                               mDeviceWindowWidth / 3.28f,
                               mDeviceWindowHeight / 1.5f + sin(M_PI * 2 / 240 * mSphereMotion) * -1.5f); // 緑
  
  mSphereRedRect = ci::Rectf(mDeviceWindowWidth / 1.6f,
                             mDeviceWindowHeight / 1.8f + sin(M_PI * 2 / 240 * mSphereMotion) * -2.5f,
                             mDeviceWindowWidth / 1.27f,
                             mDeviceWindowHeight  / 1.3f + sin(M_PI * 2 / 240 * mSphereMotion) * -2.5f); // 赤
  
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
