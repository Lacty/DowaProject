
#include "Piano.hpp"

#include "../../../resource/ResourceManager.hpp"

// Debug
using namespace std;

Piano::Piano(const ci::Vec3f& mPianoPos, const ci::Vec3f& mPianoSize)
{
  mBallStr = "Ball"; // なにと当たったか？ここではボール
  
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
  ci::gl::rotate(ci::Vec3f(180, 0, 0));
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize);
  mPiano.unbind();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Piano::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  std::string name;
  name = compare -> getName();
  name.resize(4); // 配列の要素リサイズ
  
  if(name == mBallStr)
  {
    dowa::ResourceManager::audio().get(CinderellaAudioKey::House).bgm->disable();
    dowa::ResourceManager::audio().get(CinderellaAudioKey::HousePiano).bgm->enable();
    dowa::ResourceManager::audio().get(CinderellaAudioKey::HousePiano).gain->setValue(1.0f);
  }
}
