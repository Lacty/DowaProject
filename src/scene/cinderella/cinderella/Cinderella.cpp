
#include "Cinderella.hpp"

#include "../../../resource/Resource.hpp"


Cinderella::Cinderella(const ci::Vec3f& mCinderellaPos, const ci::Vec3f& mCinderellaSize)
{
  mFloorStr = "Floor";
  
  mCount = 0;
  mGravityPower = -0.2f;
  mAcceleration = 0.f;
  
  mCinderellaStatic = TextureManager::find(ResKey::CCharacterStatic);
  mCinderellaLeft = TextureManager::find(ResKey::CCharacterLeft);
  mCinderellaRight = TextureManager::find(ResKey::CCharacterRight);
  
  mPos = mCinderellaPos;
  mSize = mCinderellaSize;
  
  setColliderType(Collider::Rect);
}

void Cinderella::setup() {}
void Cinderella::update()
{
  mPos.x += 0.8f; // 速度 0.8秒で32秒
  
  mAcceleration += mGravityPower;
  mPos.y += mAcceleration;

}

void Cinderella::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  if(mCount < 75)
  {
    ci::gl::pushModelView();
    mCinderellaLeft.bind();
    ci::gl::translate(mPos);
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
    ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
    mCinderellaLeft.unbind();
    ci::gl::popModelView();
  }
  else
  {
    ci::gl::pushModelView();
    mCinderellaRight.bind();
    ci::gl::translate(mPos);
    ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
    ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
    mCinderellaRight.unbind();
    ci::gl::popModelView();
  }
  
  if(mCount == 150) { mCount = 0; }
  
  mCount++;
  
  cinder::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  
  ci::gl::disable(GL_CULL_FACE);
}

void Cinderella::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  
  std::string name;
  name = compare -> getName();
  name.resize(5);
  
  if(name == mFloorStr)
  {
    mAcceleration = 0.0f;
    mPos.y = compare -> getPos().y + compare -> getSize().y / 2 + mSize.y / 2;
  }
  
  if(compare -> getName() == "Stairs")
  {
    mAcceleration = 0.f;
    mPos.y -= 0.5f;
  }
}
