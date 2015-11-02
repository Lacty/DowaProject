
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class DowaProjectApp : public AppNative {
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void DowaProjectApp::setup() {}

void DowaProjectApp::mouseDown(MouseEvent event) {}

void DowaProjectApp::update() {}

void DowaProjectApp::draw() {
	gl::clear(Color(0.4f, 0.4f, 0.4f));
  
  gl::pushModelView();
  gl::translate(getWindowCenter());
  gl::color(Color(1, 1, 1));
  gl::drawCube(Vec3f::zero(), Vec3f(100, 100, 100));
  gl::popModelView();
}

CINDER_APP_NATIVE( DowaProjectApp, RendererGl )
