
#include "King2.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


King2::King2(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  
  mPos = Pos;
  mSize = Size;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mKing2 = TextureManager::find(ResKey::CKing2);
  
}

void King2::setup() {}

void King2::update()
{
  
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  std::cout << mCinderellaPos.x << std::endl;
  
  if(mCinderellaPos.x > 6000)
  {
    mPos = ci::Vec3f( 6000, -115, 0);
  }
}

void King2::draw()
{
  
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  // 描画
  drawKing2(mKing2);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void King2::drawKing2(const ci::gl::Texture& texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
}
