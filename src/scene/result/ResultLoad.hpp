
#pragma once
#include "../Scene.hpp"


class ResultLoad : public Scene {
private:
  void load();

public:
  ResultLoad();
  ~ResultLoad();

  void update();
  void draw();
};
