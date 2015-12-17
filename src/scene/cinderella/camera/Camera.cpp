
#include "Camera.hpp"
#include "../../../window/Window.hpp"


namespace dowa {

Camera::Camera() :
mPos(ci::Vec3f::zero()),
mForcus(Forcus::None) {}

Camera::Camera(float fov, float _near, float _far) {
  mCamera.setPerspective(fov, ci::app::getWindowAspectRatio(), _near, _far);
}


ci::Vec3f Camera::getGazePoint() {
  switch (mForcus) {
    case None: {
      return mPos;
    } break;
    
    case One: {
      return mForcusOne->getPos();
    } break;
    
    case Two: {
      return (mForcusOne->getPos() + mForcusTwo->getPos()) * 0.5f;
    } break;
  }
}

ci::Vec2f Camera::getDistFromGazeToCamera() {
  return getGazePoint().xy() - mPos.xy();
}

float Camera::getDistFromOneToTwo() {
  assert(mForcusOne != nullptr && mForcusTwo != nullptr);
  return ci::Vec3f(mForcusTwo->getPos() - mForcusOne->getPos()).length();
}

float Camera::getDistance() {
  switch (mForcus) {
    case None: {
      return mDistMin;
    } break;
      
    case One: {
      return mDistMin;
    } break;
      
    case Two: {
      float d = getDistFromOneToTwo() + mDistMin * 1.5f;
      return d > mDistMax ? mDistMax : d;
    } break;
  }
}

void Camera::updateDist() {
  float def = getDistance() - mPos.z;
  mPos.z += def * 0.04f;
}


void Camera::setForcusNum(const Forcus forcus) {
  mForcus = forcus;
}

void Camera::setForcusObjectOne(const std::shared_ptr<Object>& obj) {
  mForcusOne = obj;
}

void Camera::setForcusObjectTwo(const std::shared_ptr<Object>& obj) {
  mForcusTwo = obj;
}

void Camera::setForcusObject(const std::shared_ptr<Object>& obj1,
                             const std::shared_ptr<Object>& obj2)
{
  mForcusOne = obj1;
  mForcusTwo = obj2;
}


void Camera::setFarClip(const ci::Vec3f &topL, const ci::Vec3f &topR,
                        const ci::Vec3f &botL, const ci::Vec3f &botR)
{
  TopLeft = topL;
  TopRight = topR;
  BotLeft = botL;
  BotRight = botR;
}

void Camera::setPos(const ci::Vec3f &pos) {
  mPos = pos;
  mCamera.setEyePoint(mPos);
}

void Camera::setDistMinMax(float min, float max) {
  mDistMin = min;
  mDistMax = max;
}

void Camera::lookAt(const ci::Vec3f& eye,
                    const ci::Vec3f& target,
                    const ci::Vec3f& up)
{
  mPos = eye;
  mCamera.lookAt(mPos, target, up);
}

void Camera::setMatrices() {
  ci::gl::setMatrices(mCamera);
}

void Camera::focus() {
  mPos.x += getDistFromGazeToCamera().x * 0.04f;
  mPos.y += getDistFromGazeToCamera().y * 0.04f;
  
  updateDist();
  
  mCamera.setEyePoint(mPos);
}

void Camera::bound() {
  ci::Vec3f topLeft;
  ci::Vec3f topRight;
  ci::Vec3f bottomLeft;
  ci::Vec3f bottomRight;
  mCamera.getFarClipCoordinates(&topLeft, &topRight, &bottomLeft, &bottomRight);
  //std::cout << "top Left  = " << topLeft << std::endl;
  //std::cout << "top Right = " << topRight << std::endl;
  //std::cout << "bot Left  = " << bottomLeft << std::endl;
  //std::cout << "bot Right = " << bottomRight << std::endl;
  
  if (topLeft.x < TopLeft.x) {
    float offset = TopLeft.x - topLeft.x;
    std::cout << offset << std::endl;
    mPos.x += offset;
    mCamera.setEyePoint(mPos);
    return;
  }
  
  if (topRight.x > TopRight.x) {
    float offset = TopLeft.x - topLeft.x;
    std::cout << offset << std::endl;
    mPos.x += offset;
    mCamera.setEyePoint(mPos);
    return;
  }
}

} // namespace dowa