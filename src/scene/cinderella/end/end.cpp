
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
  
  ci::gl::translate(dowa::getWindowCenter());
  
  ci::gl::color(1.0, 1.0, 1.0, count);
  ci::gl::draw(TextureManager::find(tex_key),
               ci::Rectf(-dowa::getWindowWidth() * 0.5f,
                         -dowa::getWindowHeight() * 0.5f,
                         dowa::getWindowWidth() * 0.5f,
                         dowa::getWindowHeight() * 0.5f));
  
  ci::gl::disableAlphaBlending();
  
  ci::gl::popModelView();
}

void End::enableStart() {
  mIsStart = true;
}