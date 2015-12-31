
#include "Plate.hpp"


Plate::Plate(const ci::Vec3f& PlatePos, const ci::Vec3f& PlateSize)
{
  mPos = PlatePos;
  mSize = PlateSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  // findは処理が重いので変数にサウンドを保存
  mPlateFallSE = AudioManager::find(ResKey::CPlateFallSE);
  
  // サウンドの音量を変更
  mPlateFallSE.setVolume(0.8f);
    
  mFallFlag = false;
  mTextureChangeFlag = false;
  mSePlayFlag = true;
  
  mPlate = TextureManager::find(ResKey::CPlate);
  mPlateFall = TextureManager::find(ResKey::CPlateFall);
  
  setColliderType(Collider::Rect);
  
}

void Plate::setup() {}

void Plate::update()
{
  if(mFallFlag) mRotate.z += 0.5f;
  if(mRotate.z == 90 && mSePlayFlag)
  {
    mFallFlag = false;
    mTextureChangeFlag = true;
    mPos = ci::Vec3f( 3350, -150, 0);
    mSize = ci::Vec3f(115, 10, 0);
    mPlateFallSE.play();
    mSePlayFlag = false;
  }
}

void Plate::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(!mTextureChangeFlag) drawPlate();
  if(mTextureChangeFlag) drawPlateFall();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Plate::drawPlate()
{
  mPlate.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::translate(ci::Vec3f(0, -50, 0));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mPlate.unbind();
}

void Plate::drawPlateFall()
{
  mPlateFall.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::translate(ci::Vec3f(0, 0, 0));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f(ci::Vec3f::zero())), mSize);
  mPlateFall.unbind();
}

void Plate::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball" && mRotate.z == 0)
  {
    mFallFlag = true;
  }
}
