
#pragma once
#include "../Scene.hpp"
#include "end/end.hpp"


class Test : public Scene {
private:
  std::shared_ptr<End> end;
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};