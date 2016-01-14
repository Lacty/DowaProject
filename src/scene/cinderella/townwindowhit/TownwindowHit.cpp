
#include "TownwindowHit.hpp"


TownwindowHit::TownwindowHit(const ci::Vec3f& Pos, const ci::Vec3f& Size, const std::string& Name)
{
  mPos = Pos;
  mSize = Size;
  
  mTownwindowName = Name;
  
  // findは処理が重いので変数にサウンドを保存
  mWindowClose = AudioManager::find(ResKey::CWindowClose);
  
  // サウンドの音量を変更
  mWindowClose.setVolume(0.8f);
  
  mTownWindowTop = TextureManager::find(ResKey::CWindowHit1);
  mTownWindowLeft = TextureManager::find(ResKey::CWindowHit2);
  mTownWindowRight = TextureManager::find(ResKey::CWindowHit3);
  mTownWindowOpen = TextureManager::find(ResKey::CWindowOpen);
  
  setColliderType(Collider::Rect);
  
}

void TownwindowHit::setup() {}

void TownwindowHit::update() {}

void TownwindowHit::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mTownwindowName == "TownWindowTop") drawTownwindow(mTownWindowTop);
  if(mTownwindowName == "TownWindowLeft") drawTownwindow(mTownWindowLeft);
  if(mTownwindowName == "TownWindowRight") drawTownwindow(mTownWindowRight);
  if(mTownwindowName == "TownWindowOpen") drawTownwindow(mTownWindowOpen);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
}

void TownwindowHit::drawTownwindow(const ci::gl::Texture& mTownwindowTexture)
{
  mTownwindowTexture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mTownwindowTexture.unbind();
}

void TownwindowHit::onCollisionUpdate(const std::shared_ptr<Object> &compare)
{
  if(compare -> getName() == "Ball" && mTownwindowName == "TownWindowOpen")
  {
    mSize = ci::Vec3f( 75, 90, 0);
    mPos.y -= 5.f;
    mTownwindowName = "TownWindowTop";
    mWindowClose.play();
  }
}
