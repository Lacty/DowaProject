#include "Loading.hpp"

Loading::Loading(){
  dowa::ResourceManager::enableTextures();
}

void Loading::update(){
  //Apply the BG texture before enabling the Audio
  static bool waitOneFrame = false;
  static bool initOnce = false;

  //Wait one frame to draw the background
  if (!waitOneFrame){
    waitOneFrame = true;
    return;
  }

  //Load audio files after the drawing of the background
  if (waitOneFrame && !initOnce){
    initOnce = true;
    dowa::ResourceManager::enableTextures();
  }
}

void Loading::draw(){
  //Draw the background
}