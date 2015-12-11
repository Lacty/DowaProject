
#include "CinderellaScene.hpp"


CinderellaScene::CinderellaScene() {
  camera = dowa::Camera(60, 0.5, 300);
  mCameraPos = Vec3f(0.0f,0.0f, 200.0f);
  mCameraTarget = Vec3f::zero();
  camera.lookAt(mCameraPos, 
    mCameraTarget, ci::Vec3f::yAxis());
  mWindowWidth = ci::app::getWindowWidth();
  mWindowHeight = ci::app::getWindowHeight();
  mBack1 = ci::Rectf(-200, tanf(M_PI / 6) * 200, 1000, -tanf(M_PI / 6) * 200);
  /*mBack2 = ci::Rectf(150,100, 300,-100);
  mBack3 = ci::Rectf(300,100,450,-100);*/
}


void CinderellaScene::update() {
  mBack1 = ci::Rectf(-200, tanf(M_PI / 6) * 200, 1000, -tanf(M_PI / 6) * 200);
  /*mBack2 = ci::Rectf(150 + mXPos, 100, 300 + mXPos, -100);
  mBack3 = ci::Rectf(300 + mXPos, 100, 450 + mXPos, -100);*/
  mCameraPos.x += 0.05f;
  mCameraTarget.x += 0.05f;
  camera.lookAt(mCameraPos, mCameraTarget, Vec3f::yAxis());
}

void CinderellaScene::draw() {
  ci::gl::enable(GL_TEXTURE_2D);
  ci::gl::pushMatrices();
  camera.setMatrices();
  
  // 描画 カメラを仕様しているので画像が反転し
  // 座標が　画面の中央が(0, 0)　１年のときに西山先生から配られたチャレンジベーシックの座標系になる
  
  ci::gl::popMatrices();
  ci::gl::disable(GL_TEXTURE_2D);
}