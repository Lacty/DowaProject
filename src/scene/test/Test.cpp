
#include "Test.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "../../device/Device.hpp"


Test::Test() {
  //setFadeOut(FadeType::FullScreen);
}

void Test::update() {
  //if (Device::isTouchBegan())
    setFadeOut(FadeType::FullScreen);
  //setNextScene(SceneType::Test, FadeType::Circle);
}

void Test::draw() {
  
}