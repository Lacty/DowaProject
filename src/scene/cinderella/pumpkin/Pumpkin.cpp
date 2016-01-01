
#include "Pumpkin.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Pumpkin::Pumpkin(const ci::Vec3f& PumpkinPos, const ci::Vec3f& PumpkinSize, const std::string& PumpkinNamef)
{
  mPos = PumpkinPos;
  mSize = PumpkinSize;
  
  mPumpkinName = PumpkinNamef;
  
  mPumpkin1 = TextureManager::find(ResKey::CPumpkin1);
  mPumpkin2 = TextureManager::find(ResKey::CPumpkin2);
  
}

void Pumpkin::setup() {}

void Pumpkin::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x > 3600 && mPumpkinName == "Pumpkin1")
  {
    mPos.y += 5;
  }
}

void Pumpkin::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mPumpkinName == "Pumpkin1") drawPumpkin(mPumpkin1);
  if(mPumpkinName == "Pumpkin2") drawPumpkin(mPumpkin2);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Pumpkin::drawPumpkin(const ci::gl::Texture & PumpkinTexture)
{
  PumpkinTexture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  PumpkinTexture.unbind();
}
