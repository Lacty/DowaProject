
#pragma once

#include "../Scene.hpp"
#include "cinder/gl/Texture.h"

#include "CinderOpenCV.h" // OpenCVに必要！

class Test : public Scene
{
private:
  cv::Mat mInput; // テスト用
  cv::Mat mOutput; // テスト用
  
  ci::gl::Texture mTexture_Test; // テスト用
  ci::Surface mSurface_Test; // テスト用
  
public:
  
  Test();
  
  void update();
  void draw();
};
