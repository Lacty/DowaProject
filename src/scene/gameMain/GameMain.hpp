
#pragma once
#include "../Scene.hpp"
#include "../fade/FadeBase.h"

class GameMain : public Scene {
private:
  
public:
  GameMain();
  
  void update();
  void draw();
};