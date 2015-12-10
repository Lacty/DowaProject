
#pragma once

#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"
#include "camera/Camera.hpp"


class CinderellaScene : public Scene {
private:
  ci::Rectf mBack1;//for debugging purposes only
  //ci::Rectf mBack2;//for debugging purposes only
  //ci::Rectf mBack3;//for debugging purposes only

  int mWindowWidth;//for debugging purposes only
  int mWindowHeight;//for debugging purposes only

  float mXPos;//for debug only
  dowa::Camera camera;
public:
  CinderellaScene();
  
  void update();
  void draw();
};