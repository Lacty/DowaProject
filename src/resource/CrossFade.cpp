
#include "CrossFade.hpp"
#include "AudioManager.hpp"


CrossFade::CrossFade(int keyIn, int keyOut, float speed) :
mIsFin(false),
mVolume(0),
mSpeed(speed),
mKeyIn(keyIn),
mKeyOut(keyOut)
{
  mIn  = AudioManager::find(keyIn);
  mOut = AudioManager::find(keyOut);
  
  mOut.play();
  mOut.setVolume(mVolume);
}


bool CrossFade::isFinish() {
  return mIsFin;
}

int CrossFade::getKeyIn() {
  return mKeyIn;
}

int CrossFade::getKeyOut() {
  return mKeyOut;
}

void CrossFade::update() {
  mVolume += mSpeed;
  
  if (mVolume > 1.0f) {
    mVolume = 1.0f;
    mIn.stop();
    mIsFin = true;
  }
  
  mIn.setVolume(1.0f - mVolume);
  mOut.setVolume(mVolume);
}