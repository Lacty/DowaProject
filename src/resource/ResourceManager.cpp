
#include "ResourceManager.hpp"

using namespace ci;
using namespace dowa;

//Audio Resource

hidden::AudioResource::AudioResource() {}

bool hidden::AudioResource::insert(std::string path, int key) {
  if (mMap[key] != nullptr) return false;

  hidden::Audio temp;

  auto ctx = audio::Context::master();

  audio::SourceFileRef sourceFile = audio::load(ci::app::loadAsset(path));
  audio::BufferRef buffer = sourceFile->loadBuffer();
  temp.bgm = ctx->makeNode(new audio::BufferPlayerNode(buffer));
  temp.gain = ctx->makeNode(new audio::GainNode(1.0f));

  temp.bgm >> temp.gain >> ctx->getOutput();

  ctx->enable();

  mMap[key] = std::make_shared<hidden::Audio>(temp);

  return true;
}

hidden::Audio hidden::AudioResource::get(int key) {
  return *mMap[key];
}

void hidden::AudioResource::clear() {
  mMap.clear();
}

//Audio Resource

//Texture Resource

hidden::TextureResource::TextureResource() {}

bool hidden::TextureResource::insert(std::string path, int key) {
  if (mMap[key] != nullptr) return false;

  auto temp = std::make_shared<gl::Texture>(loadImage(ci::app::loadAsset(path)));

  mMap[key] = temp;

  return true;
}

ci::gl::Texture hidden::TextureResource::get(int key) {
  return *mMap[key];
}

void hidden::TextureResource::clear() {
  mMap.clear();
}

//Texture Resource

//Resource Manager

void ResourceManager::enable(){//deprecated
  audio();
  texture();
}

void ResourceManager::createTextures(){
  texture();
}

void ResourceManager::createAudio(){
  audio();
}

//Resource Manager
