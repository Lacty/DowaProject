
#pragma once
#include "../Scene.hpp"


class TitleLoad : public Scene {
private:
  void load();
  
public:
  TitleLoad();
  ~TitleLoad();

  void update();
  void draw();
};
