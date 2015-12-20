
#include "Audio.hpp"


Audio::Audio(const std::string& path) {
  auto ctx = ci::audio::Context::master();
  
  auto file = ci::audio::load(ci::app::loadAsset(path));
  auto buf  = file->loadBuffer();
  
  bgm  = ctx->makeNode(new ci::audio::BufferPlayerNode(buf));
  gain = ctx->makeNode(new ci::audio::GainNode(0.0f));
  
  bgm >> gain >> ctx->getOutput();
  ctx->enable();
}

float Audio::getVolume() {
  return gain->getValue();
}

void Audio::setVolume(float volume) {
  gain->setValue(volume);
}

void Audio::play() {
  bgm->start();
}

void Audio::stop() {
  bgm->stop();
}

void Audio::enableLoop() {
  bgm->setLoopEnabled(true);
}

void Audio::disableLoop() {
  bgm->setLoopEnabled(false);
}