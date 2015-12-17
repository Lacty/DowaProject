
#include "ResultLoad.hpp"
#include "../../resource/ResourceManager.hpp"
#include "../SceneManager.hpp"


ResultLoad::ResultLoad() :
//mLoad(&ResultLoad::load, this),
isFin(false) {
  std::cout << "start result load" << std::endl;
}

ResultLoad::~ResultLoad() {
  std::cout << "end result load" << std::endl;
}

void ResultLoad::load() {
  // Texture
  dowa::ResourceManager::texture().insert("background/result/Back.jpg", TextureKey::Back);
  dowa::ResourceManager::texture().insert("background/result/Retry.jpg", TextureKey::Retry);
  dowa::ResourceManager::texture().insert("background/result/Select.jpg", TextureKey::Select);
  dowa::ResourceManager::texture().insert("background/result/Fin.jpg", TextureKey::Fin);
  dowa::ResourceManager::texture().insert("background/result/Font.png", TextureKey::Font);

  // Sound

  isFin = true;
}

void ResultLoad::update() {
  load();
  if (isFin) {
    std::cout << "finish load" << std::endl;
    //mLoad.join();
    isFin = false;
    SceneManager::create(SceneType::Result);
  }
}

void ResultLoad::draw() {}
