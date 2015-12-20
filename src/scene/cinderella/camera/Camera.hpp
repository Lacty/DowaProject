
#pragma once
#include "../../../object/Object.hpp"
#include "cinder/Camera.h"


namespace dowa {

class Camera {
private:
  ci::CameraPersp mCamera;

  ci::Vec3f mPos;
  float mOffset;
  
  ci::Vec3f TopLeft;
  ci::Vec3f TopRight;

  std::shared_ptr<Object> mForcusObj;
  
public:
  Camera();
  Camera(float fov, float _near, float _far);
  
  void setForcusObj(const std::shared_ptr<Object>& obj);
  void setOffset(float offset);
  void setStageSize(float L, float R);
  
  void setPos(const ci::Vec3f& pos);
  void lookAt(const ci::Vec3f& eye, const ci::Vec3f& target, const ci::Vec3f& up);
  
  void setMatrices();
  void focus();
  
  void bound();
  
  void update();
};

}