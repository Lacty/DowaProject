
#pragma once
#include "../Scene.hpp"
#include "../../object/Object.hpp"
#include "../../resource/Resource.hpp"

#include "T.hpp"

class Test : public Scene {
private:
  std::shared_ptr<T> mT;
  
public:
  Test();
  ~Test();
  
  void update();
  void draw();
};
