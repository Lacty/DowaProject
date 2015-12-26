
#pragma once
#include <unordered_map>
#include <list>
#include <memory>
#include "Audio.hpp"
#include "CrossFade.hpp"


class AudioManager {
private:
  std::unordered_map<int, std::shared_ptr<Audio>> mMap;
  std::list<CrossFade> mList;
  std::list<int>       mFadingList;
  
  AudioManager() = default;
  static AudioManager& get();
  
public:
  static void enable();

  static void   add(int key);
  static Audio& find(int key);
  
  static void addCrossFade(int keyIn, int keyOut, float speed = 0.01f);
  static void update();
  
  static void clear();
};
