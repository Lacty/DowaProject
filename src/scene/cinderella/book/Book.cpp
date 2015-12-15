
#include "Book.hpp"

#include "../../../object/Task.hpp"
#include "../../../resource/ResourceManager.hpp"
#include "../../../scene/SceneManager.hpp"

Book::Book(const ci::Vec3f& mBookPos, const ci::Vec3f& mBookSize, const std::string& mBookNamef)
{
  mPos = mBookPos;
  mSize = mBookSize;
  mRotate = ci::Vec3f(ci::Vec3f::zero());
  mBookName = mBookNamef;
  
  mGravityPower = 0.01f;
  mGravityPower2 = 0.08f;
  mAcceleration = 0.f;
  
  mBookOpenName = "BookOpen";
  mBookPileName = "BookPile";
  mBookSideName = "BookSide";
  
  mFallFlag = false;
  
  mCinderellaPos = ci::Vec3f(ci::Vec3f::zero());
  
  mBookPile = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookPile);
  mBookOpen = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookOpen);
  mBookSide = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookSide);
  
  setColliderType(Collider::Rect);
}

void Book::setup() {}

void Book::update()
{
  
  mCinderellaPos = Task::find("Cinderella")->getPos();
  
  if(mCinderellaPos.x > 1068 || mFallFlag)
  {
    if(mRotate.z < 90) {
      mAcceleration += mGravityPower;
      mRotate.z += mAcceleration;
    }
    else if (mBookName == mBookSideName) {
      mAcceleration += mGravityPower2;
      mPos.y -= mAcceleration;
    }
  }
}

void Book::draw()
{
  ci::gl::pushModelView();
  ci::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  if(mBookName == mBookPileName) drawBookPile();
  if(mBookName == mBookSideName) drawBookSide();
  if(mBookName == mBookOpenName) drawBookOpen();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Book::drawBookPile()
{
  mBookPile.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBookPile.unbind();
}

void Book::drawBookOpen()
{
  mBookOpen.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBookOpen.unbind();
}

void Book::drawBookSide()
{
  mBookSide.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBookSide.unbind();
}

void Book::onCollisionUpdate(const std::shared_ptr<Object>& compare)
{
  if(compare -> getName() == "Ball") mFallFlag = true;
  
  if(compare -> getName() == "Floor_Floor") mBookName = "BookOpen";
  
  if(compare -> getName() == "Cinderella" && mBookName == "BookSide")
    SceneManager::create(SceneType::Test);
}
