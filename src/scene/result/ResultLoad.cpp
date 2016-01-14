
#include "ResultLoad.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"
#include "../../window/Window.hpp"


ResultLoad::ResultLoad() {
  std::cout << "start result load" << std::endl;
  TextureManager::add(ResKey::NowLoad);
  count = -1;
}

ResultLoad::~ResultLoad() {
  std::cout << "end result load" << std::endl;
}

void ResultLoad::load() {
  // Texture
  // Back
  // Retry
  // Select
  // Fin
  // Font

  // Sound
  
  std::cout << "finish load" << std::endl;
}

void ResultLoad::update() {
  ++count;
  if (!count) return;

  load();
  SceneManager::create(SceneType::Result);
}

void ResultLoad::draw() {
  ci::gl::clear(ci::Color(0.4f, 0.4f, 0.4f));
  
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  ci::gl::Texture image = TextureManager::find(ResKey::NowLoad);
  float offset_x = dowa::getWindowWidth() - image.getWidth();
  float offset_y = dowa::getWindowHeight() - image.getHeight();
  ci::gl::translate(offset_x, offset_y);
  ci::gl::draw(image);
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
}
