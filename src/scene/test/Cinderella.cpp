
#include "Cinderella.hpp"
#include "../../object/Object.hpp"
#include "cinder/app/AppNative.h"
#include "../../resource/ResourceManager.hpp"
#include "../../device/Device.hpp"
#include "../../object/Task.hpp"

Cinderella::Cinderella(ci::Vec3f mCinderellaPos, ci::Vec3f mCinderellaSize)
{
  
  mFloorStr = "Floor"; // 床名前判定
  
  mCount = 0; // アニメーション
  mGravityPower += 0.2f; // 重力パワー
  
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
  mPos.x++;
  
  // 重力計算
  mAccelerationY += mGravityPower;
  mPos.y += mAccelerationY;
}

void Cinderella::draw()
{
  
  ci::gl::pushModelView();
  cinder::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  if(mCount < 75)
  {
    mCinderellaLeft.bind();
    ci::gl::drawCube(mPos, mSize);
    mCinderellaLeft.unbind();
  }
  else
  {
    mCinderellaRight.bind();
    ci::gl::drawCube(mPos, mSize);
    mCinderellaRight.unbind();
  }
  
  if(mCount == 150) { mCount = 0; }
  
  mCount++;
  
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::disable(GL_CULL_FACE);
  
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
    mPos.y = compare -> getPos().y - compare -> getSize().y / 2 - mSize.y / 2;
  }
}
