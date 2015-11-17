
#include "Title.hpp"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

Title::Title() {}

void Title::update() {
  setNextScene(SceneType::GameMain, FadeType::None);
}

void Title::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(ci::app::getWindowCenter());
  ci::gl::color(ci::Color(1, 1, 1));
  ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(100, 100, 100));
  ci::gl::popModelView();
}