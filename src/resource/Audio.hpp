
#pragma once
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
#include "cinder/audio/NodeEffects.h"


class Audio {
private:
  ci::audio::BufferPlayerNodeRef bgm;
  ci::audio::GainNodeRef         gain;
  
  std::shared_ptr<ci::audio::SourceFile>     file;
  std::shared_ptr<ci::audio::BufferT<float>> buf;
  
public:
  Audio() = default;
  Audio(const std::string& path);
  ~Audio();
  
  float getVolume();
  void  setVolume(float volume);
  
  void play();
  void stop();
  void enableLoop();
  void disableLoop();
  
  void clear();
};