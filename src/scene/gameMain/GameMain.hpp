
#pragma once
#include "../Scene.hpp"

#include "cinder/app/AppNative.h"

class GameMain : public Scene {
private:
  
public:
  GameMain();
  
  void update();
  void draw();
};