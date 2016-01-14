
#include "end.hpp"
#include "../../../window/Window.hpp"
#include "../../../resource/Resource.hpp"


End::End(int key) : mIsStart(false), count(0.0f), tex_key(key) {}

void End::setup() {}

void End::update() {
  if (!mIsStart) return;
  
  count += 0.01f;
}

void End::draw() {
  ci::gl::pushModelView();
  
  ci::gl::enableAlphaBlending();
  
  ci::gl::translate(cam_pos.xy());
  
  ci::gl::color(1.0, 1.0, 1.0, count);
  ci::gl::rotate(ci::Vec3f(180, 0, 0));
  ci::gl::draw(TextureManager::find(tex_key),
               ci::Rectf(-dowa::getWindowWidth() * 0.5f,
                         -dowa::getWindowHeight() * 0.5f,
                         dowa::getWindowWidth() * 0.5f,
                         dowa::getWindowHeight() * 0.5f));
  ci::gl::color(1.0f, 1.0f, 1.0f, 1.0f);
  
  ci::gl::disableAlphaBlending();
  
  ci::gl::popModelView();
}

void End::enableStart() {
  mIsStart = true;
}

void End::setCamPos(const ci::Vec3f &pos) {
  cam_pos = pos;
}