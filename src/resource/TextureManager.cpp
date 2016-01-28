
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
  get().mMap.erase(key);
  if (get().mMap.find(key) == get().mMap.end()) {
    std::cout << key << "を削除" << std::endl;
  }
}

void TextureManager::clear() {
  get().mMap.clear();
}