
#include "Camera.hpp"
#include "../../../window/Window.hpp"


namespace dowa {

Camera::Camera() :
mPos(ci::Vec3f::zero()),
mOffset(0.0f) {}

Camera::Camera(float fov, float _near, float _far) {
  mCamera.setPerspective(fov, ci::app::getWindowAspectRatio(), _near, _far);
}


void Camera::setForcusObj(const std::shared_ptr<Object>& obj) {
  mForcusObj = obj;
}

void Camera::setOffset(float offset) {
  mOffset = offset;
}

void Camera::setStageSize(float L, float R)
{
  TopLeft    = ci::Vec3f::zero();
  TopLeft.x  = L;
  TopRight   = ci::Vec3f::zero();
  TopRight.x = R;
}

void Camera::setPos(const ci::Vec3f &pos) {
  mPos = pos;
  mCamera.setEyePoint(mPos);
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
  mPos.x = mForcusObj->getPos().x + mOffset;
  
  mCamera.setEyePoint(mPos);
}

void Camera::bound() {
  // カメラにうつる範囲を取得
  ci::Vec3f topLeft;
  ci::Vec3f topRight;
  ci::Vec3f bottomLeft;
  ci::Vec3f bottomRight;
  mCamera.getFarClipCoordinates(&topLeft, &topRight, &bottomLeft, &bottomRight);
  
  // 描画範囲がステージ外に出ないようにする
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

void Camera::update() {
  setMatrices();
  focus();
  bound();
}

} // namespace dowa