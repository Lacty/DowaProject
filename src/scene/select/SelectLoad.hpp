
#pragma once
#include "../Scene.hpp"
#include <thread>


class SelectLoad : public Scene {
private:
  std::thread mLoad;
  bool isFin;
  void load();

public:
  SelectLoad();
  ~SelectLoad();

  void update();
  void draw();
};
