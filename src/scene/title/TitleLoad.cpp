
#include "TitleLoad.hpp"
#include "../../object/Task.hpp"
#include "../../resource/Resource.hpp"
#include "../SceneManager.hpp"



TitleLoad::TitleLoad() {
  std::cout << "start title load" << std::endl;
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

void TitleLoad::draw() {}