
#pragma once

#include "../Scene.hpp"
#include "../../resource/ResourceManager.hpp"
#include "camera/Camera.hpp"


class CinderellaScene : public Scene
{
  
private:
  
  ci::Rectf mBack1; // 1枚
  
  ci::Rectf mBack21; // 4枚
  ci::Rectf mBack22;
  ci::Rectf mBack23;
  ci::Rectf mBack24;
  
  ci::Rectf mBack3; // 1枚

  float mDeviceWindowHeight, mDeviceWindowWidth; // デバイスウィンドサイズ
  
  // やない
  ci::Vec3f mcameraPos;
  dowa::Camera camera;
  
public:
  
  CinderellaScene();
  ~CinderellaScene();
  
  void update();
  void draw();
};
