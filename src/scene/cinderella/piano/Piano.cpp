
#include "Piano.hpp"

#include "../CinderellaScene.hpp"


Piano::Piano(const ci::Vec3f& mPianoPos, const ci::Vec3f& mPianoSize)
{
  mIsPlay = true;
  mVolume = 0.0f;
  mFadeSpeed = 0.05f;
  
  mPos = mPianoPos;
  mSize = mPianoSize;
  
  // findは処理が重いので変数にサウンドを保存
  mHousePiano = AudioManager::find(ResKey::CHousePiano);
  
  // サウンドの音量を変更
  mHousePiano.setVolume(0.0f);
  
  mPiano = TextureManager::find(ResKey::CPiano);
  
  setColliderType(Collider::Rect);
}

void Piano::setup(){}

void Piano::update() {}

void Piano::draw()
{
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  mPiano.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mPiano.unbind();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
}

void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball" && mIsPlay)
  {
    // サウンドの音量を変更
    mHousePiano.setVolume(0.8f);
    
    AudioManager::addCrossFade(ResKey::CHouse, ResKey::CHousePiano);
    
    mIsPlay = false;
  }
}
