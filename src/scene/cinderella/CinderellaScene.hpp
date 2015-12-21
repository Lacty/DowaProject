
#pragma once

#include "camera/Camera.hpp"
#include "cinder/gl/Texture.h"

#include "../Scene.hpp"
#include "../../resource/Resource.hpp"


class CinderellaScene : public Scene
{
  
private:
  
  ci::Rectf mBack1; // 1枚
  
  ci::Rectf mBack21; // 4枚
  ci::Rectf mBack22;
  ci::Rectf mBack23;
  ci::Rectf mBack24;
  
  ci::Rectf mBack3; // 1枚
  
  ci::gl::Texture mBack1Texutre;
  ci::gl::Texture mBack2Texutre;
  ci::gl::Texture mBack3Texutre;

  float mDeviceWindowHeight, mDeviceWindowWidth; // デバイスウィンドサイズ
  
  // やない
  ci::Vec3f mCameraPos;
  dowa::Camera camera;
  
public:
  
  CinderellaScene();
  ~CinderellaScene();
  
  void update();
  void draw();
};
