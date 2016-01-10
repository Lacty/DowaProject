
#pragma once
#include "../Scene.hpp"


class CinderellaLoad : public Scene {
private:
  void load();
  int count;

public:
  CinderellaLoad();
  ~CinderellaLoad();

  void update();
  void draw();
};
