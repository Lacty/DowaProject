
#include "CinderellaScene.hpp"


CinderellaScene::CinderellaScene() {
  camera = dowa::Camera(60, 0.5, 300);
  mCameraPos = Vec3f(0.0f,0.0f, 200.0f);
  mCameraTarget = Vec3f::zero();
  camera.lookAt(mCameraPos, 
    mCameraTarget, ci::Vec3f::yAxis());
  mWindowWidth = ci::app::getWindowWidth();
  mWindowHeight = ci::app::getWindowHeight();
  mBack1 = ci::Rectf(-150, tanf(M_PI / 6) * 200, 450, -tanf(M_PI / 6) * 200);
  /*mBack2 = ci::Rectf(150,100, 300,-100);
  mBack3 = ci::Rectf(300,100,450,-100);*/
}


void CinderellaScene::update() {
  mBack1 = ci::Rectf(-150, tanf(M_PI / 6) * 200, 450, -tanf(M_PI / 6) * 200);
  /*mBack2 = ci::Rectf(150 + mXPos, 100, 300 + mXPos, -100);
  mBack3 = ci::Rectf(300 + mXPos, 100, 450 + mXPos, -100);*/
  mCameraPos.x += 0.1f;
  mCameraTarget.x += 0.1f;
  camera.lookAt(mCameraPos, mCameraTarget, Vec3f::yAxis());
}

void CinderellaScene::draw() {
  ci::gl::enable(GL_TEXTURE_2D);

  camera.setMatrices();

  ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaFull), mBack1);
  //ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack2), mBack2);
  //ci::gl::draw(dowa::Resource::texture().get(CinderellaTKey::_betaBack3), mBack3);

  ci::gl::disable(GL_TEXTURE_2D);
}