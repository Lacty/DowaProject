
#pragma once
#include "../../../object/Object.hpp"


class End : public Object {
private:
  bool mIsStart;
  float count;
  int tex_key;
  
  ci::Vec3f cam_pos;

public:
  End() = default;
  End(int key);
  
  void setup();
  void update();
  void draw();
  
  void enableStart();
  
  void setCamPos(const ci::Vec3f& pos);
};