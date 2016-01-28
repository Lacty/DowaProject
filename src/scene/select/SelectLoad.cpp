
#include "SelectLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"


SelectLoad::SelectLoad() :
//mLoad(&SelectLoad::load, this),
isFin(false) {
  std::cout << "start select load" << std::endl;
}

SelectLoad::~SelectLoad() {
  std::cout << "end select load" << std::endl;
}


void SelectLoad::load() {
  // Texture
  dowa::ResourceManager::texture().insert("background/stageSelect/StageSelectBack.png", TextureKey::StageSelectBack);
  dowa::ResourceManager::texture().insert("object/stageSelect/StageSelectBook.png", TextureKey::StageSelectBook);
  dowa::ResourceManager::texture().insert("object/stageSelect/Cinderella.png", TextureKey::StageSelectCinderella);

  // Sound
  dowa::ResourceManager::audio().insert("sound/se/StageSelected.m4a", AudioKey::StageSelectSE);

  isFin = true;
}

void SelectLoad::update() {
  load();
  if (isFin) {
    std::cout << "finish load" << std::endl;
    //mLoad.join();
    isFin = false;
    SceneManager::create(SceneType::Test);
  }
};

void SelectLoad::draw() {}
