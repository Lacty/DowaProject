
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
  mBookOpenName = "mBookOpen";
  mBookPileName = "mBookPile";
  mBookDroppedName = "mBookDropped";
  mBookBackName = "mBookBack";
  
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
  
  mBookPile.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本４
  mBookPile.unbind();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}
