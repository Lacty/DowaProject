
#include "Shop.hpp"

#include "../../../resource/Resource.hpp"


Shop::Shop(const ci::Vec3f& ShopPos, const ci::Vec3f& ShopSize)
{
  mPos = ShopPos;
  mSize = ShopSize;
  
  mShop = TextureManager::find(ResKey::CShop);
  
}

void Shop::setup() {}

void Shop::update() {}

void Shop::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mShop.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mShop.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
