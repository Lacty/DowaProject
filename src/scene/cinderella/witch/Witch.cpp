
#include "Witch.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Witch::Witch(const ci::Vec3f& WitchPos, const ci::Vec3f& WitchSize)
{
  
  mTexChange = false;
  
  mPos = WitchPos;
  mSize = WitchSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mWitch1 = TextureManager::find(ResKey::CWitch1);
  mWitch2 = TextureManager::find(ResKey::CWitch2);
  
}

void Witch::setup() {}

void Witch::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x > 3600)
  {
    mTexChange = true;
  }
}

void Witch::draw()
{
  
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mTexChange) drawWitch(mWitch2);
  else drawWitch(mWitch1);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Witch::drawWitch(const ci::gl::Texture& texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
}
