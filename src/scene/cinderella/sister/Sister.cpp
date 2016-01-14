
#include "Sister.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Sister::Sister(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  
  mPos = Pos;
  mSize = Size;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mSister1 = TextureManager::find(ResKey::CSister1);
  mSister2 = TextureManager::find(ResKey::CSister2);
  mSister3 = TextureManager::find(ResKey::CSister3);
  
}

void Sister::setup() {}

void Sister::update() {}

void Sister::draw()
{
  
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  // 描画
  if(mCinderellaPos.x <= 5320) drawSister(mSister1);
  if(mCinderellaPos.x >= 5321 && mCinderellaPos.x <= 5500) drawSister(mSister2);
  if(mCinderellaPos.x >= 5501) drawSister(mSister3);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Sister::drawSister(const ci::gl::Texture& texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
}
