
#include <iostream>
#include "TextureManager.hpp"
#include "ResKey.hpp"


TextureManager& TextureManager::get() {
  static TextureManager instance;
  return instance;
}

void TextureManager::enable() {
  get();
}

void TextureManager::add(int key) {
  // keyにすでに登録されていたら処理をストップ
  assert(get().mMap[key] == nullptr);
  
  std::string path = ResKey::getPath(key);
  auto audio = std::make_shared<ci::gl::Texture>(loadImage(ci::app::loadAsset(path)));
  
  get().mMap[key] = audio;
  std::cout << "[" << path << "]を追加しました" << std::endl;
}

ci::gl::Texture& TextureManager::find(int key) {
  return *get().mMap[key];
}

void TextureManager::kill(int key) {
  auto itr = get().mMap.find(key);
  if (itr != get().mMap.end()) {
    get().mMap.erase(itr);
  }
}

void TextureManager::clear() {
  get().mMap.clear();
}