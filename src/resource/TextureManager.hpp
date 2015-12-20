
#pragma once
#include <unordered_map>
#include <string>

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"


class TextureManager {
private:
  std::unordered_map<int, std::shared_ptr<ci::gl::Texture>> mMap;
  
  TextureManager() = default;
  static TextureManager& get();
  
public:
  static void enable();
  
  static void             add(int key);
  static ci::gl::Texture& find(int key);
  
  static void clear();
};
