
#pragma once
#include "../Scene.hpp"
#include <thread>


class TitleLoad : public Scene {
private:
  std::thread mLoad;
  bool isFin;
  void load();
  
public:
  TitleLoad();
  ~TitleLoad();

  void update();
  void draw();
};
