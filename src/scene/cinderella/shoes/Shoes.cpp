
#include "Shoes.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Shoes::Shoes(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  mPos = Pos;
  mSize = Size;
  
  mShoes = TextureManager::find(ResKey::CShoes);
  
}

void Shoes::setup() {}

void Shoes::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x >= 6100)
  {
    mPos = ci::Vec3i( 6100, -150, 0);
  }
}

void Shoes::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  // draw
  drawShoes(mShoes);
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  ci::gl::disable(GL_CULL_FACE);
}

void Shoes::drawShoes(const ci::gl::Texture & tex)
{
  tex.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  tex.unbind();
}
