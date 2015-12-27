
#include "River.hpp"

#include "../../../resource/Resource.hpp"


River::River(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mRiver = TextureManager::find(ResKey::CRiver);
  
}

void River::setup() {}

void River::update() {}

void River::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mRiver.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mRiver.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
