
#include "SelectLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"


SelectLoad::SelectLoad() : mLoad(&SelectLoad::load, this), isFin(false) {}


void SelectLoad::load() {
  // Texture
  dowa::ResourceManager::texture().insert("background/stageSelect/StageSelectBack.png", TextureKey::StageSelectBack);
  dowa::ResourceManager::texture().insert("object/stageSelect/StageSelectBook.png", TextureKey::StageSelectBook);
  dowa::ResourceManager::texture().insert("object/stageSelect/Cinderella.png", TextureKey::StageSelectCinderella);

  // Sound
  dowa::ResourceManager::audio().insert("sound/se/StageSelected.ogg", AudioKey::StageSelectSE);

  isFin = true;
}

void SelectLoad::update() {
  if (isFin) {
    std::cout << "finish load" << std::endl;
    mLoad.join();
    SceneManager::create(SceneType::Select);
    isFin = false;
  }
};

void SelectLoad::draw() {}
