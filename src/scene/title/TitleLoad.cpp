
#include "TitleLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"



TitleLoad::TitleLoad() :
//mLoad(&TitleLoad::load, this),
isFin(false) {
  std::cout << "start title load" << std::endl;
}

TitleLoad::~TitleLoad() {
  std::cout << "end title load" << std::endl;
}


void TitleLoad::load() {
  std::lock_guard<std::mutex> lock(mtx);

  std::cout << ci::app::getWindowHeight() << std::endl;
  
  // Texture
  dowa::ResourceManager::texture().insert("background/title/TitleBack.png",         TextureKey::TitleBack);
  dowa::ResourceManager::texture().insert("background/title/FeatherBookResize.png", TextureKey::FeatherBook);
  dowa::ResourceManager::texture().insert("background/title/Logo.png",              TextureKey::Logo);
  dowa::ResourceManager::texture().insert("background/title/TapToStartEng.png",     TextureKey::TapToStartEng);
  dowa::ResourceManager::texture().insert("background/title/Trace.png",             TextureKey::Trace);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterTa.png",      TextureKey::LetterTa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterMa.png",      TextureKey::LetterMa);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterKo.png",      TextureKey::LetterKo);
  dowa::ResourceManager::texture().insert("background/title/KanaLetterRo.png",      TextureKey::LetterRo);
  dowa::ResourceManager::texture().insert("background/title/SphereBlue.png",        TextureKey::SphereBlue);
  dowa::ResourceManager::texture().insert("background/title/SphereGreen.png",       TextureKey::SphereGreen);
  dowa::ResourceManager::texture().insert("background/title/SphereRed.png",         TextureKey::SphereRed);
  
  // Sound
  dowa::ResourceManager::audio().insert("sound/bgm/Menu.m4a", AudioKey::Menu);
  dowa::ResourceManager::audio().insert("sound/se/GameStart.m4a", AudioKey::GameStartSE);
  
  isFin = true;
}

void TitleLoad::update() {
  load();
  if (isFin) {
    std::cout << "finish load" << std::endl;
    isFin = false;
    SceneManager::create(SceneType::Title);
  }
}

void TitleLoad::draw() {}
