
#pragma once
#include "../Scene.hpp"
#include "../../resource/Resource.hpp"


class Test : public Scene {
private:
//  Audio mHitSE;
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
