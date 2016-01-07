
#include "GateSide.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


GateSide::GateSide(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  
  mPos = Pos;
  mSize = Size;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mGateSide = TextureManager::find(ResKey::CGateSide);
  
}

void GateSide::setup() {}

void GateSide::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x > 4480)
  {
    mPos = ci::Vec3i( 4790, -6, 0);
  }
}

void GateSide::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mGateSide.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mGateSide.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
