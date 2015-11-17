
#include "GameMain.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

GameMain::GameMain() {}

void GameMain::update() {
  setNextScene(SceneType::Result, FadeType::None);
}

void GameMain::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(ci::app::getWindowCenter());
  ci::gl::color(ci::Color(1, 0, 0));
  ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(100, 100, 100));
  ci::gl::popModelView();
}