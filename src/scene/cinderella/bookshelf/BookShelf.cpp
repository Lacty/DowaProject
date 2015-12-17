
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
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  mBookShelf.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(ci::Vec3f(180.f, 0.f, 0.f));
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  mBookShelf.unbind();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  ci::gl::popModelView();
}
