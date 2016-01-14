
#include "Horse.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Horse::Horse(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mCount = 0;
  mAcceleration = 0.f;
  mGravityPower = 0.03f;
  
  mHorse1 = TextureManager::find(ResKey::CHorse1);
  mHorse2 = TextureManager::find(ResKey::CHorse2);
  mHorse3 = TextureManager::find(ResKey::CHorse3);
  mHorse4 = TextureManager::find(ResKey::CHorse4);
  mHorse5 = TextureManager::find(ResKey::CHorse5);
  mHorse6 = TextureManager::find(ResKey::CHorse6);
  
}

void Horse::setup() {}

void Horse::update()
{
  
  ci::Vec3i mPumpkinPos = Task::find("Pumpkin1") -> getPos();
  
  if(mPumpkinPos.y > 200)
  {
    if((int)mPos.y > -70)
    {
      mAcceleration += mGravityPower;
      mPos.y -= mAcceleration;
    }
  }
  
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
 
  if(mCinderellaPos.y == -80 && mCinderellaPos.x > 3500 && mCinderellaPos.x < 4950)
  {
    mPos.x += 1.073f;
    mCount++;
  }
  
}

void Horse::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mCount <= 10) drawHorse(mHorse1);
  if(mCount >= 10 && mCount <= 20) drawHorse(mHorse2);
  if(mCount >= 20 && mCount <= 30) drawHorse(mHorse3);
  if(mCount >= 30 && mCount <= 40) drawHorse(mHorse4);
  if(mCount >= 40 && mCount <= 50) drawHorse(mHorse5);
  if(mCount >= 50 && mCount <= 60) drawHorse(mHorse6);
  
  if(mCount == 60) mCount = 0;
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Horse::drawHorse(ci::gl::Texture & texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
}
