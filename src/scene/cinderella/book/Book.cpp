
#include "Book.hpp"

#include "../../../resource/ResourceManager.hpp"

// 位置、サイズ、名前
Book::Book(const ci::Vec3f& mBookPos, const ci::Vec3f& mBookSize, const std::string& mBookNamef)
{
  mPos = mBookPos;
  mSize = mBookSize;
  
  // 引数の名前を代入
  mBookName = mBookNamef;
  
  // 本の名前初期化
  mBookOpenName = "BookOpen";
  mBookPileName = "BookPile";
  mBookDroppedName = "BookDropped";
  mBookBackName = "BookBack";
  
  // Texture代入
  mBookPile = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookPile); // 本４冊
  mBookBack = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookBack); // 本縦
  mBookDropped = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookDropped); // 落下
  mBookOpen = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookOpen); // オープン状態
  
  setColliderType(Collider::Rect);
}

void Book::setup() {}

void Book::update() {}

void Book::draw()
{
  ci::gl::pushModelView();
  ci::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  if(mBookName == mBookBackName) drawBookBack();
  if(mBookName == mBookDroppedName) drawBookDropped();
  if(mBookName == mBookPileName) drawBookPile();
  if(mBookName == mBookOpenName) drawBookOpen();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}

void Book::drawBookBack()
{
  mBookBack.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本４
  mBookBack.unbind();
}

void Book::drawBookDropped()
{
  mBookDropped.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本４
  mBookDropped.unbind();
}

void Book::drawBookPile()
{
  mBookPile.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本４
  mBookPile.unbind();
}

void Book::drawBookOpen()
{
  mBookOpen.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本４
  mBookOpen.unbind();
}
