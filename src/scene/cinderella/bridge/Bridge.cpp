
#include "Bridge.hpp"

#include "../../../resource/Resource.hpp"


Bridge::Bridge(const ci::Vec3f& BridgePos, const ci::Vec3f& BridgeSize)
{
  mPos = BridgePos;
  mSize = BridgeSize;
  
  mBridge = TextureManager::find(ResKey::CBridge);
  
}

void Bridge::setup() {}

void Bridge::update() {}

void Bridge::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  mBridge.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBridge.unbind();
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}
