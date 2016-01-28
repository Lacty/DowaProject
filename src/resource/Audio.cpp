
#include "Audio.hpp"
#include "cinder/app/AppNative.h"


Audio::Audio(const std::string& path) {
  auto ctx = ci::audio::Context::master();
  
  file = ci::audio::load(ci::app::loadAsset(path));
  buf  = file->loadBuffer();
  
  bgm  = ctx->makeNode(new ci::audio::BufferPlayerNode(buf));
  gain = ctx->makeNode(new ci::audio::GainNode(0.0f));
  
  bgm >> gain >> ctx->getOutput();
  ctx->enable();
}

Audio::~Audio() {}

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


void Audio::clear() {
  file->~SourceFile();
  buf->~BufferT();
  //bgm->~BufferPlayerNode();
  //gain->~GainNode();
}