
#pragma once

#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"
#include "camera/Camera.hpp"


class CinderellaScene : public Scene {
private:
  using Vec3f = ci::Vec3f;
  ci::Rectf mBack1;//for debugging purposes only
  //ci::Rectf mBack2;//for debugging purposes only
  //ci::Rectf mBack3;//for debugging purposes only

  int mWindowWidth;//for debugging purposes only
  int mWindowHeight;//for debugging purposes only


  Vec3f mCameraPos;//debug only
  Vec3f mCameraTarget;//debug only
  dowa::Camera camera;
public:
  CinderellaScene();
  
  void update();
  void draw();
};