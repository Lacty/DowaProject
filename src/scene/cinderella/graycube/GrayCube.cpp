
#include "GrayCube.hpp"

#include "../../../resource/Resource.hpp"


GrayCube::GrayCube(const ci::Vec3i& Pos, const ci::Vec3i& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mGrayCube = TextureManager::find(ResKey::CGrayCube);
  
}

void GrayCube::setup() {}

void GrayCube::update() {}

void GrayCube::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mGrayCube.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mGrayCube.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
