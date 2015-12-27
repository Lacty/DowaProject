
#include "TownwindowHit.hpp"

#include "../../../resource/Resource.hpp"


TownwindowHit::TownwindowHit(const ci::Vec3f& Pos, const ci::Vec3f& Size, const std::string& Name)
{
  mPos = Pos;
  mSize = Size;
  
  mTownwindowName = Name;
  
  mTownWindowTop = TextureManager::find(ResKey::CWindow1);
  mTownWindowLeft = TextureManager::find(ResKey::CWindow2);
  mTownWindowRight = TextureManager::find(ResKey::CWindow3);
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
    std::cout << compare -> getName() << std::endl;
    
    mSize = ci::Vec3f( 75, 90, 0);
    mPos.y -= 5.f;
    mTownwindowName = "TownWindowTop";
  }
}
