
#pragma once
#include "../../../object/Object.hpp"


class End : public Object {
private:
  bool mIsStart;
  float count;
  int tex_key;

public:
  End() = default;
  End(int key);
  
  void setup();
  void update();
  void draw();
  
  void enableStart();
};