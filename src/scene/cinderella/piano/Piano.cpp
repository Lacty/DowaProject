
#include "Piano.hpp"

#include "../../../resource/ResourceManager.hpp"

Piano::Piano(const ci::Vec3f& mPianoPos, const ci::Vec3f& mPianoSize)
{
  mPos = mPianoPos;
  mSize = mPianoSize;
  
  mPiano = dowa::ResourceManager::texture().get(CinderellaTextureKey::Piano);
  
　setColliderType(Collider::Rect);
}

void Piano::setup(){}

void Piano::update() {}

void Piano::draw()
{
  ci::gl::pushModelView();
  ci::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  mPiano.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mPiano.unbind();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball")
  {
    dowa::ResourceManager::audio().get(CinderellaAudioKey::House).bgm->disable();
    dowa::ResourceManager::audio().get(CinderellaAudioKey::HousePiano).gain->setValue(1.0f);
    dowa::ResourceManager::audio().get(CinderellaAudioKey::HousePiano).bgm->enable();
  }
}
