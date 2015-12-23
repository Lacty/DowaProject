
#include "LampPost.hpp"

#include "../../../resource/Resource.hpp"


LampPost::LampPost(const ci::Vec3f& LampPostPos, const ci::Vec3f& LampPostSize)
{
  mPos = LampPostPos;
  mSize = LampPostSize;
  
  mLampPost = TextureManager::find(ResKey::CLampPost);
  
}

void LampPost::setup() {}

void LampPost::update() {}

void LampPost::draw()
{
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mLampPost.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mLampPost.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
}
