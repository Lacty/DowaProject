
#pragma once
#include <unordered_map>
#include <memory>
#include "Audio.hpp"


class AudioManager {
private:
  std::unordered_map<int, std::shared_ptr<Audio>> mMap;
  
  AudioManager() = default;
  static AudioManager& get();
  
public:
  static void enable();

  static void   add(int key);
  static Audio& find(int key);
  
  static void clear();
};
