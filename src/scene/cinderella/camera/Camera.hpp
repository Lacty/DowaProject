
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
  
  ci::Vec3f TopLeft;
  ci::Vec3f TopRight;
  ci::Vec3f BotLeft;
  ci::Vec3f BotRight;

  std::shared_ptr<Object> mForcusOne;
  std::shared_ptr<Object> mForcusTwo;
  
  ci::Vec3f getGazePoint();
  ci::Vec2f getDistFromGazeToCamera();
  float     getDistFromOneToTwo();
  float     getDistance();
  void      updateDist();
  
public:
  Camera();
  Camera(float fov, float _near, float _far);
  
  void setForcusNum(const Forcus forcus);
  
  void setForcusObjectOne(const std::shared_ptr<Object>& obj);
  void setForcusObjectTwo(const std::shared_ptr<Object>& obj);
  void setForcusObject(const std::shared_ptr<Object>& obj1, const std::shared_ptr<Object>& obj2);
  
  void setFarClip(const ci::Vec3f& topL, const ci::Vec3f& topR,
                  const ci::Vec3f& botL, const ci::Vec3f& botR);
  
  void setPos(const ci::Vec3f& pos);
  void setDistMinMax(float min, float max);
  void lookAt(const ci::Vec3f& eye, const ci::Vec3f& target, const ci::Vec3f& up);
  
  void setMatrices();
  void forcus();
  
  void bound();
};

}