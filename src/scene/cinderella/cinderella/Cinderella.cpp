
#include "Cinderella.hpp"
#include "../../../object/Object.hpp"
#include "cinder/app/AppNative.h"
#include "../../../resource/ResourceManager.hpp"
#include "../../../device/Device.hpp"
#include "../../../object/Task.hpp"

// 読み取り専用
Cinderella::Cinderella(const ci::Vec3f& mCinderellaPos, const ci::Vec3f& mCinderellaSize)
{
  mFloorStr = "Floor"; // 床名前判定
  
  mCount = 0; // アニメーション
  mGravityPower -= 0.2f; // 重力パワー
  
  dowa::ResourceManager::texture().insert("character/cinderella/1.png", CinderellaTextureKey::CharacterStatic);
  dowa::ResourceManager::texture().insert("character/cinderella/2.png", CinderellaTextureKey::CharacterLeft);
  dowa::ResourceManager::texture().insert("character/cinderella/3.png", CinderellaTextureKey::CharacterRight);
  
  mCinderellaStatic = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterStatic);
  mCinderellaLeft = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterLeft);
  mCinderellaRight = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterRight);;
  
  // コンストラクタでシンデレラの座標初期化
  mPos = mCinderellaPos;
  mSize = mCinderellaSize;
  
  setColliderType(Collider::Rect); // 当たり判定
}

void Cinderella::setup() {}
void Cinderella::update()
{
  mPos.x += 1.8f; // 速度 0.8秒で32秒
  
  // 重力計算
  mAccelerationY += mGravityPower;
  mPos.y += mAccelerationY;
}

void Cinderella::draw()
{
  ci::gl::pushModelView();
  cinder::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enable(GL_CULL_FACE);
  
  if(mCount < 75)
  {
    ci::gl::pushModelView();
    mCinderellaLeft.bind();
    ci::gl::translate(mPos); // 移動させる
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f)); // 回転
    ci::gl::drawCube(ci::Vec3f(0.f, 0.f, 0.f), mSize);
    mCinderellaLeft.unbind();
    ci::gl::popModelView();
  }
  else
  {
    ci::gl::pushModelView();
    mCinderellaRight.bind();
    ci::gl::translate(mPos); // 移動させる
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f)); // 回転
    ci::gl::drawCube(ci::Vec3f(0.f, 0.f, 0.f), mSize);
    mCinderellaRight.unbind();
    ci::gl::popModelView();
  }
  
  if(mCount == 150) { mCount = 0; }
  
  mCount++;
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  cinder::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Cinderella::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  
  std::string name;
  name = compare -> getName();
  name.resize(5); // 配列の要素リサイズ
  
  if(name == mFloorStr)
  {
    mAccelerationY = 0.0f;
    mPos.y = compare -> getPos().y + compare -> getSize().y / 2 + mSize.y / 2;
  }
}
