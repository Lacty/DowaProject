
#include "TitleLoad.hpp"
#include "../../object/Task.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"
#include "../../window/Window.hpp"



TitleLoad::TitleLoad() {
  std::cout << "start title load" << std::endl;
  TextureManager::add(ResKey::NowLoad);
  count = -1;
}

TitleLoad::~TitleLoad() {
  std::cout << "end title load" << std::endl;
  TextureManager::kill(ResKey::NowLoad);
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
  float offset_x = dowa::getWindowWidth() - TextureManager::find(ResKey::NowLoad).getWidth();
  float offset_y = dowa::getWindowHeight() - TextureManager::find(ResKey::NowLoad).getHeight();
  ci::gl::translate(offset_x, offset_y);
  ci::gl::draw(TextureManager::find(ResKey::NowLoad));
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
}