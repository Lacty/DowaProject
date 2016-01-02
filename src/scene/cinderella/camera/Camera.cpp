
#include "Camera.hpp"
#include "../../../window/Window.hpp"


namespace dowa {

Camera::Camera() :
mPos(ci::Vec3f::zero()),
mOffset(0.0f),
offset(0.0f),
mScale(0.0f),
mIsGameOver(false) {}

Camera::Camera(float fov, float _near, float _far) {
  mCamera.setPerspective(fov, ci::app::getWindowAspectRatio(), _near, _far);
  mImage = TextureManager::find(ResKey::CamHole);
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
  mCamera.setEyePoint(mPos);
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
  
  // 画面の左はじの座標を取得
  mViewLeft = topLeft.x;
  mViewRight = topRight.x;
  mViewTop = topLeft.y;
  mViewBottom = bottomLeft.y;
  
  // 描画範囲がステージ外に出ないようにする
  if (topLeft.x < TopLeft.x) {
    float offset = TopLeft.x - topLeft.x;
    //std::cout << offset << std::endl;
    mPos.x += offset;
    mCamera.setEyePoint(mPos);
    return;
  }
  
  if (topRight.x > TopRight.x) {
    float offset = TopLeft.x - topLeft.x;
    //std::cout << offset << std::endl;
    mPos.x += offset;
    mCamera.setEyePoint(mPos);
    return;
  }
}

float Camera::getViewLeft() {
  return mViewLeft;
}

float Camera::getViewRight() {
  return mViewRight;
}

float Camera::getViewTop() {
  return mViewTop;
}

float Camera::getViewBottom() {
  return mViewBottom;
}

void Camera::setGameOver(float offset) {
  if (mIsGameOver) return;
  mIsGameOver = true;
  mScale = 18.0f;
  mAngle = 0.0f;
  float time = 2.0f;
  this->offset = offset;
  ci::app::timeline().apply(&mScale,
                            3.0f,
                            time, ci::easeOutSine);
  ci::app::timeline().apply(&mAngle,
                            mOffset,
                            time, ci::easeOutSine);
}

void Camera::update() {
  focus();
  bound();
  
  if (mIsGameOver) {
    //std::cout << mAngle << std::endl;
    mPos.x -= mAngle;
  }
  
  setMatrices();
}

void Camera::draw() {
  if (!mIsGameOver) return;
  
  ci::gl::enable(GL_TEXTURE_2D);
  cinder::gl::enableAlphaBlending();
  
  ci::gl::pushModelView();
  
  ci::Vec2f halfsize = mImage.getSize() * 0.5f;
  ci::gl::translate(mForcusObj->getPos().xy());
  ci::gl::translate(ci::Vec2f(offset, 0.0f));
  ci::gl::scale(mScale, mScale);
  ci::gl::translate(-halfsize);
  ci::gl::draw(mImage);
  
  ci::gl::popModelView();
  
  ci::gl::disableAlphaBlending();
  ci::gl::disable(GL_TEXTURE_2D);
}

} // namespace dowa