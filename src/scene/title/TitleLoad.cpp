
#include "TitleLoad.hpp"
#include "../../object/Task.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"
#include "../../window/Window.hpp"



TitleLoad::TitleLoad() {
  std::cout << "start title load" << std::endl;
  TextureManager::add(ResKey::TBack);
  count = -1;
}

TitleLoad::~TitleLoad() {
  std::cout << "end title load" << std::endl;
}


void TitleLoad::load() {
  // Texture
  TextureManager::add(ResKey::TBack);
  TextureManager::add(ResKey::TFeatherBook);
  TextureManager::add(ResKey::TLogo);
  TextureManager::add(ResKey::TTapToStartEng);
  TextureManager::add(ResKey::TTrance);
  TextureManager::add(ResKey::TTa);
  TextureManager::add(ResKey::TMa);
  TextureManager::add(ResKey::TKo);
  TextureManager::add(ResKey::TRo);
  TextureManager::add(ResKey::TSphereBlue);
  TextureManager::add(ResKey::TSphereGreen);
  TextureManager::add(ResKey::TSphereRed);
  
  // Sound
  AudioManager::add(ResKey::TMenu);
  AudioManager::add(ResKey::TGameStartSE);
  
  std::cout << "finish load" << std::endl;
}

void TitleLoad::update() {
  ++count;
  if (!count) return;

  load();
  SceneManager::create(SceneType::Title);
}

void TitleLoad::draw() {
  ci::gl::clear(ci::Color(0.4f, 0.4f, 0.4f));
  
  ci::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  ci::gl::Texture image = TextureManager::find(ResKey::TBack);
  float offset_x = dowa::getWindowWidth() - image.getWidth();
  float offset_y = dowa::getWindowHeight() - image.getHeight();
  ci::gl::translate(offset_x, offset_y);
  ci::gl::draw(image);
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
}