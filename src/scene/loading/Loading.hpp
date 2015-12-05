
#pragma once
#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"

class Loading : public Scene{
private:
  bool mAudioInitOnce;
public:
  Loading();

  void update();
  void draw();
};