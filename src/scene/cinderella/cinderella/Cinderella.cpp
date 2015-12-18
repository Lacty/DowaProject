
#include "Cinderella.hpp"

#include "../../../resource/ResourceManager.hpp"

Cinderella::Cinderella(const ci::Vec3f& mCinderellaPos, const ci::Vec3f& mCinderellaSize)
{
  mFloorStr = "Floor"; // 床名前判定
  
  mCount = 0; // アニメーション
  mGravityPower = -0.2f; // 重力パワー
  mAccelerationY = 0.f;
  
  mCinderellaStatic = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterStatic);
  mCinderellaLeft = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterLeft);
  mCinderellaRight = dowa::ResourceManager::texture().get(CinderellaTextureKey::CharacterRight);;
  
  // コンストラクタでシンデレラの座標初期化
  mPos = mCinderellaPos;
  mSize = mCinderellaSize;
  
  setColliderType(Collider::Rect);
}

void Cinderella::setup() {}
void Cinderella::update()
{
  mPos.x += 0.8f; // 速度 0.8秒で32秒
  
  // 重力計算
  mAccelerationY += mGravityPower;
  mPos.y += mAccelerationY;
}

void Cinderella::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  if(mCount < 75)
  {
    ci::gl::pushModelView();
    mCinderellaLeft.bind();
    ci::gl::translate(mPos);
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
    ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
    mCinderellaLeft.unbind();
    ci::gl::popModelView();
  }
  else
  {
    ci::gl::pushModelView();
    mCinderellaRight.bind();
    ci::gl::translate(mPos);
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
    ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
    mCinderellaRight.unbind();
    ci::gl::popModelView();
  }
  
  if(mCount == 150) { mCount = 0; }
  
  mCount++;
  
  cinder::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  
  ci::gl::disable(GL_CULL_FACE);
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
