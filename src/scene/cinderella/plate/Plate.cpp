
#include "Plate.hpp"

#include "../../../resource/Resource.hpp"


Plate::Plate(const ci::Vec3f& PlatePos, const ci::Vec3f& PlateSize)
{
  mPos = PlatePos;
  mSize = PlateSize;
  
  mPlate = TextureManager::find(ResKey::CPlate);
  mPlateFall = TextureManager::find(ResKey::CPlateFall);
  
}

void Plate::setup() {}

void Plate::update() {}

void Plate::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mPlate.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mPlate.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
