
#pragma once
#include "../Scene.hpp"


class CinderellaLoad : public Scene {
private:
  bool isFin;
  void load();

public:
  CinderellaLoad();
  ~CinderellaLoad();

  void update();
  void draw();
};
