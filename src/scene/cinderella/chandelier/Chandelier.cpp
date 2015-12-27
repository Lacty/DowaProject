
#include "Chandelier.hpp"

#include "../../../resource/Resource.hpp"


Chandelier::Chandelier(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mChandelier = TextureManager::find(ResKey::CHydrant);
  
}

void Chandelier::setup() {}

void Chandelier::update() {}

void Chandelier::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mChandelier.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mChandelier.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
