
#include <iostream>
#include "AudioManager.hpp"
#include "ResKey.hpp"


AudioManager& AudioManager::get() {
  static AudioManager instance;
  return instance;
}

void AudioManager::enable() {
  get();
}

void AudioManager::add(int key) {
  // keyにすでに登録されていたら処理をストップ
  assert(get().mMap[key] == nullptr);
  
  std::string path = ResKey::getPath(key);
  auto audio = std::make_shared<Audio>(path);
  
  get().mMap[key] = audio;
  std::cout << "[" << path << "]を追加しました" << std::endl;
}

Audio& AudioManager::find(int key) {
  return *get().mMap[key];
}

void AudioManager::clear() {
  get().mMap.clear();
}