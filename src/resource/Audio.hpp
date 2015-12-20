
#pragma once
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"
#include "cinder/audio/NodeEffects.h"


class Audio {
private:
  ci::audio::BufferPlayerNodeRef bgm;
  ci::audio::GainNodeRef         gain;
  
public:
  Audio() = default;
  Audio(const std::string& path);
  
  float getVolume();
  void  setVolume(float volume);
  
  void play();
  void stop();
  void enableLoop();
  void disableLoop();
};