
#pragma once
#include "../Scene.hpp"
#include <thread>


class ResultLoad : public Scene {
private:
  std::thread mLoad;
  bool isFin;
  void load();

public:
  ResultLoad();

  void update();
  void draw();
};
