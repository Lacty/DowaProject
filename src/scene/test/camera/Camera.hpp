
#pragma once
#include "../../../object/Object.hpp"
#include "cinder/Camera.h"


namespace dowa {

class Camera {
public:
  enum Forcus {
    None,
    One,
    Two
  };

private:
  ci::CameraPersp mCamera;

  ci::Vec3f mPos;
  float     mDistMin, mDistMax;
  Forcus    mForcus;

  std::shared_ptr<Object> mForcusOne;
  std::shared_ptr<Object> mForcusTwo;
  
  ci::Vec3f getGazePoint();
  ci::Vec2f getDistFromGazeToCamera();
  float     getDistFromOneToTwo();
  float     getDistance();
  void      updateDist();
  
public:
  Camera();
  Camera(float fov, float near, float far);
  
  void setForcusNum(const Forcus forcus);
  
  void setForcusObjectOne(const std::shared_ptr<Object>& obj);
  void setForcusObjectTwo(const std::shared_ptr<Object>& obj);
  void setForcusObject(const std::shared_ptr<Object>& obj1, const std::shared_ptr<Object>& obj2);
  
  void setPos(const ci::Vec3f& pos);
  void setDistMinMax(float min, float max);
  void lookAt(const ci::Vec3f& eye, const ci::Vec3f& target, const ci::Vec3f& up);
  
  void setMatrices();
  void forcus();
};

}