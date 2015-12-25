
#include "Book.hpp"

#include "../../../object/Task.hpp"
#include "../../../resource/Resource.hpp"
#include "../../../scene/SceneManager.hpp"


Book::Book(const ci::Vec3f& mBookPos, const ci::Vec3f& mBookSize, const std::string& mBookNamef)
{
  mPos = mBookPos;
  mSize = mBookSize;
  mRotate = ci::Vec3f(ci::Vec3f::zero());
  mBookName = mBookNamef;
  
  mGravityPower = 0.06f;
  mGravityPower2 = 0.08f;
  mAcceleration = 0.f;
  
  mBookOpenName = "BookOpen";
  mBookPileName = "BookPile";
  mBookSideName = "BookSide";
  
  // findは処理が重いので変数にサウンドを保存
  mBookDrop = AudioManager::find(ResKey::CBookDrop);
  mBookHit = AudioManager::find(ResKey::CBookHit);
  
  // サウンドの音量を変更
  mBookDrop.setVolume(1.0f);
  mBookHit.setVolume(1.0f);
  
  mFallFlag = false;
  mDoropAudioFlag = false;
  
  mCinderellaPos = ci::Vec3f(ci::Vec3f::zero());
  
  mBookPile = TextureManager::find(ResKey::CBookPile);
  mBookOpen = TextureManager::find(ResKey::CBookOpen);
  mBookSide = TextureManager::find(ResKey::CBookSide);
  
  setColliderType(Collider::Rect);
}

void Book::setup() {}

void Book::update()
{
  
  mCinderellaPos = Task::find("Cinderella") -> getPos();
  
  if(mCinderellaPos.x > 1068 || mFallFlag)
  {
    if(mRotate.z < 90) {
      mAcceleration += mGravityPower;
      mRotate.z += mAcceleration;
    }
    else if (mBookName == mBookSideName) {
      mAcceleration += mGravityPower2;
      mPos.y -= mAcceleration;
      
      mDoropAudioFlag = true;
    }
  }
  
  if((int)mPos.y == -156 && mDoropAudioFlag == true)
  {
    mBookDrop.play();
    mDoropAudioFlag = false;
  }
}

void Book::draw()
{
  ci::gl::pushModelView();
  ci::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  if(mBookName == mBookPileName) drawBook(mBookPile, ci::Vec3f(180.f, 0.f, 0.f));
  if(mBookName == mBookSideName) drawBook(mBookSide, ci::Vec3f(ci::Vec3f(mRotate)));
  if(mBookName == mBookOpenName) drawBook(mBookOpen, ci::Vec3f(180.f, 0.f, 0.f));
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Book::drawBook(const ci::gl::Texture& mTexturef, const ci::Vec3f& mRotatef)
{
  mTexturef.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotatef);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mTexturef.unbind();
  
//  std::cout << "BookPos = " <<  mPos << std::endl;
}

void Book::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball")
  {
    mFallFlag = true;
    mBookHit.play();
  }
  
  if(compare -> getName() == "Floor_Floor") mBookName = "BookOpen";
  
  if(compare -> getName() == "Cinderella" && mBookName == "BookSide")
  {
    std::cout << "シンデレラと当たりました" << std::endl;
  }
}
