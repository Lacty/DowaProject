
#pragma once
#include "Audio.hpp"


class CrossFade {
private:
  bool mIsFin;
  float mVolume;
  float mSpeed;
  
  Audio mIn;
  Audio mOut;
  
  int mKeyIn;
  int mKeyOut;

public:
  CrossFade() = default;
  CrossFade(int keyIn, int keyOut, float speed);
  
  bool isFinish();
  
  int getKeyIn();
  int getKeyOut();
  
  void update();
};