
#include "Result.hpp"
#include "cinder/gl/gl.h"


Result::Result() {}

void Result::update() {
  
}

void Result::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(ci::app::getWindowCenter());
  ci::gl::color(ci::Color(0, 1, 0));
  ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(100, 100, 100));
  ci::gl::popModelView();
}