
#pragma once
#include "../Scene.hpp"


class TitleLoad : public Scene {
private:
  void load();
  int count;
  
public:
  TitleLoad();
  ~TitleLoad();
  
  void update();
  void draw();
};