
#include "Hydrant.hpp"

#include "../../../resource/Resource.hpp"


Hydrant::Hydrant(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mHydrant = TextureManager::find(ResKey::CHydrant);
  
}

void Hydrant::setup() {}

void Hydrant::update() {}

void Hydrant::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mHydrant.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mHydrant.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
