
#pragma once
#include "../../../object/Object.hpp"


class Ball : public Object {
private:
  ci::Vec3f mAcc;
  ci::Vec3f mRot;
  ci::Quatf mQua;
  float speedRate;

public:
  Ball(const ci::Vec3f& pos, const ci::Vec3f& size, float speedRate = 0.2f);
  
  void setup();
  void update();
  void draw();
};
