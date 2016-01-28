
#pragma once
#include "../Scene.hpp"


class ResultLoad : public Scene {
private:
  void load();
  int count;

public:
  ResultLoad();
  ~ResultLoad();

  void update();
  void draw();
};
