
#include "Cinderella.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


Cinderella::Cinderella(const ci::Vec3f& mCinderellaPos, const ci::Vec3f& mCinderellaSize)
{
  mFloorStr = "Floor";
  
  mCount = 0;
  mGravityPower = 0.2f;
  mAcceleration = 0.f;
  mGameOverOffset = 0.f;
  
  mBookHitFlag = false;
  mSetFlag = true;
  mRiverHitFlag = false;
  mGameOverRturen = false;
  
  mStairs2Hit = false;
  
  mDanceSetFlag = false;
  mDanceFlag = false;
  
  mDressFlag = false;
  
  mOut1 = false, mOut2 = false;
  
  mOffSet = ci::Vec3f( 0.f, 0.f, 0.f);
  
  mCinderellaLeft = TextureManager::find(ResKey::CCinderella2);
  mCinderellaRight = TextureManager::find(ResKey::CCinderella3);
  mCinderellaBookHit = TextureManager::find(ResKey::CCinderellaDown);
  mCinderellaSubmerge = TextureManager::find(ResKey::CCinderellaCry);
  mCinderellaDance = TextureManager::find(ResKey::CCinderellaDance);
  mCinderellaDress1 = TextureManager::find(ResKey::CDress1);
  mCinderellaDress2 = TextureManager::find(ResKey::CDress2);
  
  mCinderellaOut1 = TextureManager::find(ResKey::COut1);
  mCinderellaOut2 = TextureManager::find(ResKey::COut2);
  mCinderellaOut3 = TextureManager::find(ResKey::COut3);
  mCinderellaOut4 = TextureManager::find(ResKey::COut4);
  
  mPos = mCinderellaPos;
  mSize = mCinderellaSize;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  setColliderType(Collider::Rect);
  
}

void Cinderella::setup() {}

void Cinderella::update()
{
  // 両方がGameOverでなければ移動させる
  if(mBookHitFlag) {}
  else if(mRiverHitFlag) {}
  else mPos.x += 0.7f;
  
  // 本と当たってなければ重力をつける
  if(!mBookHitFlag) mAcceleration += mGravityPower;
  if(!mBookHitFlag) mPos.y -= mAcceleration;
  
  // 一回しか実行しない
  if(mBookHitFlag && mSetFlag) bookHitSet();
  
  // 本を回転させる
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
  
  // 一回しか実行しない
  if(mDanceSetFlag)
  {
    danceSet();
    mDanceSetFlag = false;
  }
  
  // 馬車が出たら服を変える
  if(mPos.x > 3600) mDressFlag = true;
  
  // 王子と衝突したとき踊る
  if(mDanceFlag && mPos.x < 6000)
  {
    if(mSize.x < 100) mSize.x += 2.f;
    else danceSet();
//    std::cout << mSize.x << std::endl; // Debug
  }
  
  // 到底の位置に行ったら王子と離れる
  if(mPos.x >= 6000)
  {
    mDanceFlag = false;
    mSize = ci::Vec3f( 75, 75, 0);
    mOut1 = true;
  }
  
  // 特定の(ry
  if(mPos.x >= 6100)
  {
    mOut1 = false;
    mOut2 = true;
  }
  
}

void Cinderella::draw()
{
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::pushModelView();
  
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  if(mCount <= 75 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && !mDressFlag)
    drawCinderella(mCinderellaLeft, mOffSet);
  
  if(mCount >= 75 && mCount <= 150 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && !mDressFlag)
    drawCinderella(mCinderellaRight, mOffSet);
  
  if(mCount <= 75 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mDressFlag)
    drawCinderella(mCinderellaDress1, mOffSet);
  
  if(mCount >= 75 && mCount <= 150 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mDressFlag)
    drawCinderella(mCinderellaDress2, mOffSet);
  
  if(mCount <= 75 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mOut1)
    drawCinderella(mCinderellaOut1, mOffSet);
  
  if(mCount >= 75 && mCount <= 150 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mOut1)
    drawCinderella(mCinderellaOut2, mOffSet);
  
  if(mCount <= 75 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mOut2)
    drawCinderella(mCinderellaOut3, mOffSet);
  
  if(mCount >= 75 && mCount <= 150 && !mBookHitFlag && !mRiverHitFlag && !mDanceFlag && mOut2)
    drawCinderella(mCinderellaOut4, mOffSet);

  if(mDanceFlag) drawDance();
  
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

void Cinderella::drawDance()
{
  ci::gl::pushModelView();
  
  mCinderellaDance.bind();
  ci::gl::translate(mPos);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mCinderellaDance.unbind();
  
  ci::gl::popModelView();
}

void Cinderella::bookHitSet()
{
  mPos = ci::Vec3f( 1216, -150, 0);
  mSize = ci::Vec3f( 100, 50, 0);
  mRotate = mRotate = ci::Vec3f( 180.f, 0.f, -45.f);
  mOffSet = ci::Vec3f(0.f, -25.f, 0.f);
  mAcceleration = 0.f;
  mGravityPower = 0.03f;
  mSetFlag = false;
}

void Cinderella::danceSet()
{
  mSize = ci::Vec3f( -100, 85, 0);
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
  
  if(compare -> getName() == "King")
  {
    mDanceSetFlag = true;
    mDanceFlag = true;
    compare -> setState(State::Dead);
  }
}
