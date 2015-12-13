
#include "BookShelf.hpp"

#include "../../../resource/ResourceManager.hpp"

BookShelf::BookShelf(const ci::Vec3f& mBookPos, const ci::Vec3f& mBookSize)
{
  mPos = mBookPos;
  mSize = mBookSize;
  
  mBookShelf = dowa::ResourceManager::texture().get(CinderellaTextureKey::BookShelf); // 本棚
  
  setColliderType(Collider::Rect);
}

void BookShelf::setup() {}

void BookShelf::update() {}

void BookShelf::draw()
{
  ci::gl::pushModelView();
  ci::gl::enableAlphaBlending();
  
  ci::gl::enable(GL_CULL_FACE);
  ci::gl::enable(GL_TEXTURE_2D);
  
  mBookShelf.bind();
  ci::gl::translate(mPos); // 移動させる
  ci::gl::rotate(ci::Vec3f(180, 0, 0)); // 回転
  ci::gl::drawCube(ci::Vec3f(0, 0, 0), mSize); // 本棚
  mBookShelf.unbind();
  
  ci::gl::disable(GL_CULL_FACE);
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disableAlphaBlending();
  ci::gl::popModelView();
}
