
#include "Cinderella.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Cinderella::Cinderella(const ci::Vec3f& mCinderellaPos, const ci::Vec3f& mCinderellaSize)
{
  mFloorStr = "Floor";
  
  mCount = 0;
  mGravityPower = -0.2f;
  mAcceleration = 0.f;
  mGameOverOffset = 0.f;
  
  mBookHitFlag = false;
  mSetFlag = true;
  mRiverHitFlag = false;
  mGameOverRturen = false;
  
  mStairs2Hit = false;
  
  mOffSet = ci::Vec3f( 0, 0, 0);
  
  mCinderellaStatic = TextureManager::find(ResKey::CCharacterStatic);
  mCinderellaLeft = TextureManager::find(ResKey::CCharacterLeft);
  mCinderellaRight = TextureManager::find(ResKey::CCharacterRight);
  
  mCinderellaBookHit = TextureManager::find(ResKey::CCharacterBookHit);
  mCinderellaSubmerge = TextureManager::find(ResKey::CcharacterSubmerge);
  
  mPos = mCinderellaPos;
  mSize = mCinderellaSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  setColliderType(Collider::Rect);
}

void Cinderella::setup() {}
void Cinderella::update()
{
  if(mBookHitFlag) {}
  else if(mRiverHitFlag) {}
//  else if(mStairs2Hit && (int)mPos.y > -70) {}
  else mPos.x += 0.7f; // 速度 0.7fで30秒
  
  if(!mBookHitFlag) mAcceleration += mGravityPower;
  if(!mBookHitFlag) mPos.y += mAcceleration;
  
  // 一回しか実行しない
  if(mBookHitFlag && mSetFlag)
  {
    mPos = ci::Vec3f( 1216, -150, 0);
    mSize = ci::Vec3f( 100, 50, 0);
    mRotate = mRotate = ci::Vec3f( 180.f, 0.f, -45.f);
    mOffSet = ci::Vec3f(0.f, -25.f, 0.f);
    mAcceleration = 0.f;
    mGravityPower = 0.03f;
    mSetFlag = false;
  }
  
  if(mBookHitFlag && (int)mRotate.z != 0)
  {
    mAcceleration += mGravityPower;
    mRotate.z += mAcceleration;
    mOffSet = ci::Vec3f( 50, 0, 0);
  }
  if(mBookHitFlag && (int)mRotate.z == 0)
  {
    mGameOverRturen = true;
    mGameOverOffset = 60.0f;
  }
}

void Cinderella::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  if(mCount <= 75 && !mBookHitFlag && !mBookHitFlag && !mRiverHitFlag)
    drawCinderella(mCinderellaLeft, mOffSet);
  
  if(mCount >= 75 && mCount <= 150 && !mBookHitFlag && !mRiverHitFlag)
    drawCinderella(mCinderellaRight, mOffSet);
  
  if(mBookHitFlag) drawCinderella(mCinderellaBookHit, mOffSet);
  if(mRiverHitFlag) drawCinderella(mCinderellaSubmerge, mOffSet);
  
  if(mCount == 150) mCount = 0;
  
  if(!mBookHitFlag) mCount++;
  
  cinder::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
  
  ci::gl::disable(GL_CULL_FACE);
}

void Cinderella::drawCinderella(const ci::gl::Texture & texture, const ci::Vec3f& offset)
{
  ci::gl::pushModelView();
  
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::translate(offset);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
  
  ci::gl::popModelView();
}

void Cinderella::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  
  using std::cout;
  using std::endl;
  
  std::string name;
  name = compare -> getName();
  name.resize(5);
  
  if(compare -> getName() == "Plate")
  {
    mAcceleration = 0.f;
    mPos.y = -117.2f;
  }
  
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
  
  if(compare -> getName() == "BookSide" && (int)compare -> getPos().y != -156)
  {
    mBookHitFlag = true;
  }
  
  if(compare -> getName() == "GameOver")
  {
    mRiverHitFlag = true;
    mAcceleration = 0.f;
    mPos.y = compare -> getPos().y + compare -> getSize().y / 2 + mSize.y / 2;
    mGameOverRturen = true;
    mGameOverOffset = 0.f;
  }
  
  if(compare -> getName() == "Stairs2" && mPos.y < -80)
  {
    mAcceleration = 0.f;
    mPos.y += 0.27f;
    mStairs2Hit = true;
  }
}
