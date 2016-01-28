
#include "Orchestra.hpp"

#include "../../../resource/Resource.hpp"


Orchestra::Orchestra(const ci::Vec3i& Pos, const ci::Vec3i& Size, const std::string& str)
{
  
  mPos = Pos;
  mSize = Size;
  
  mOrchestraName = str;
  
  mOrchestra1 = TextureManager::find(ResKey::COrchestra1);
  mOrchestra2 = TextureManager::find(ResKey::COrchestra2);
  
}

void Orchestra::setup() {}

void Orchestra::update() {}

void Orchestra::draw()
{
  
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  if(mOrchestraName == "Orchestra1") drawOrchestra(mOrchestra1);
  if(mOrchestraName == "Orchestra2") drawOrchestra(mOrchestra2);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void Orchestra::drawOrchestra(const ci::gl::Texture& tex)
{
  tex.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  tex.unbind();
}
