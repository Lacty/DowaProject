
#pragma once
#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"

class Loading : public Scene{
private:
  bool mAudioInitOnce;

  ci::Font mFont;
public:
  Loading();

  void update();
  void draw();
};