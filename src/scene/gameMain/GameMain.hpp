
#pragma once
#include "../Scene.hpp"
#include "../fade/FadeBase.hpp"

class GameMain : public Scene {
private:
  
public:
  GameMain();
  
  void update();
  void draw();
};