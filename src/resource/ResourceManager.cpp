#include "ResourceManager.hpp"

using namespace ci;
using namespace dowa;

//Audio Resource

hidden::AudioResource::AudioResource() {
  //insert(filepath, AudioKey.TheKey);  
}

bool hidden::AudioResource::insert(std::string path, AudioKey key) {
  hidden::AudioIterator it = mappedResource.find(key);

  if (it != mappedResource.end()) {
    return false;
  }

  hidden::Audio temp;

  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile = audio::load(ci::app::loadAsset(path));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  temp.bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));
  temp.gain = ctx->makeNode(new audio::GainNode(1.0f));

  temp.bgm >> temp.gain >> ctx->getOutput();

  ctx->enable();

  std::pair<AudioKey, hidden::Audio> res (key, temp);

  mappedResource.insert(res);

  return true;
}

hidden::Audio hidden::AudioResource::get(AudioKey key) {
  return mappedResource.find(key)->second;
}

//Audio Resource

//Texture Resource

hidden::TextureResource::TextureResource() {
  //insert(filepath, TextureKey.TheKey);
}

bool hidden::TextureResource::insert(std::string path, TextureKey key) {
  hidden::TextureIterator it = mappedResource.find(key);

  if (it != mappedResource.end()) {
    return false;
  }

  gl::Texture temp;

  temp = gl::Texture(loadImage(ci::app::loadAsset("images/donut_0.png")));

  std::pair<TextureKey, gl::Texture> res (key, temp);

  mappedResource.insert(res);

  return true;
}

ci::gl::Texture hidden::TextureResource::get(TextureKey key) {
  return mappedResource.find(key)->second;
}

//Texture Resource