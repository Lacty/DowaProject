
#include "King.hpp"

#include "../../../resource/Resource.hpp"
#include "../../../object/Task.hpp"


King::King(const ci::Vec3f& Pos, const ci::Vec3f& Size)
{
  
  mPos = Pos;
  mSize = Size;
  mRotate = ci::Vec3f(180.f, 0.f, 0.f);
  
  mKing1 = TextureManager::find(ResKey::CKing1);
  mKing2 = TextureManager::find(ResKey::CKing2);
  
  setColliderType(Collider::Rect);
  
}

void King::setup() {}

void King::update()
{
  ci::Vec3i mCinderellaPos = Task::find("Cinderella") -> getPos();
}

void King::draw()
{
  
  ci::gl::enable(GL_CULL_FACE);
  
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  // 描画
  drawKing(mKing1);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
  
  ci::gl::disable(GL_CULL_FACE);
  
}

void King::drawKing(const ci::gl::Texture& texture)
{
  texture.bind();
  ci::gl::translate(mPos);
  ci::gl::rotate(mRotate);
  ci::gl::drawCube(ci::Vec3f(ci::Vec3f::zero()), mSize);
  texture.unbind();
}

void King::onCollisionUpdate(const std::shared_ptr<Object>& compare) {}
