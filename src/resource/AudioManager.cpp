
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

void AudioManager::addCrossFade(int keyIn, int keyOut, float speed) {
  // すでに操作中のものがあれば追加をしない
  for (auto it : get().mFadingList) {
    if (it == keyIn || it == keyOut) return;
  }

  get().mList.emplace_back(keyIn, keyOut, speed);
  get().mFadingList.emplace_back(keyIn);
  get().mFadingList.emplace_back(keyOut);
}

void AudioManager::update() {
  auto itr = get().mList.begin();
  while(itr != get().mList.end()) {
    itr->update();
    
    // 処理が終了したものがあれば削除
    if (itr->isFinish()) {
    
      // keyのリストから削除
      auto it = get().mFadingList.begin();
      while (it != get().mFadingList.end()) {
        if (*it == itr->getKeyIn() || *it == itr->getKeyOut()) {
          it = get().mFadingList.erase(it);
          continue;
        }
        ++it;
      }
      
      // 削除
      itr = get().mList.erase(itr);
    }
    else {
      ++itr;
    }
  }
}

void AudioManager::clear() {
  get().mMap.clear();
  get().mList.clear();
}