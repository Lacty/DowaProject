
#pragma once

#include "camera/Camera.hpp"
#include "cinder/gl/Texture.h"

#include "../Scene.hpp"
#include "../../resource/Resource.hpp"


class CinderellaScene : public Scene
{
  
private:
  
  ci::Rectf mCinderellaHouseRect1; // 1枚
  
  ci::Rectf mCinderellaHouseRect2_1; // 4枚
  ci::Rectf mCinderellaHouseRect2_2;
  ci::Rectf mCinderellaHouseRect2_3;
  ci::Rectf mCinderellaHouseRect2_4;
  
  ci::Rectf mCinderellaHouseRect3; // 1枚
  
  ci::gl::Texture mCinderellaHouse1;
  ci::gl::Texture mCinderellaHouse2;
  ci::gl::Texture mCinderellaHouse3;

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
