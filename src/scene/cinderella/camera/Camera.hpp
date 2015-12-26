
#pragma once
#include "../../../object/Object.hpp"
#include "../../../resource/Resource.hpp"

#include "cinder/Camera.h"

#include "cinder/Timeline.h"
#include "cinder/Tween.h"


namespace dowa {

class Camera {
private:
  ci::CameraPersp mCamera;

  ci::Vec3f mPos;
  float mOffset;
  
  ci::Vec3f TopLeft;
  ci::Vec3f TopRight;
  
  float mViewLeft;
  float mViewRight;
  float mViewTop;
  float mViewBottom;
  
  ci::gl::Texture mImage;
  ci::Anim<float> mScale;
  
  ci::Anim<float> mAngle;
  bool mIsGameOver;

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
  void draw();
  
  float getViewLeft();
  float getViewRight();
  float getViewTop();
  float getViewBottom();
  
  void setGameOver();
};

}