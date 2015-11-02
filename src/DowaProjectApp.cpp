
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "scene/Scene.hpp"
#include "scene/SceneManager.hpp"


using namespace ci;
using namespace ci::app;

class DowaProjectApp : public AppNative {
private:
  SceneManager scene;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void DowaProjectApp::setup() {
  scene = SceneManager(SceneType::Title);
}

void DowaProjectApp::mouseDown(MouseEvent event) {}

void DowaProjectApp::update() {
  scene.update();
}

void DowaProjectApp::draw() {
	gl::clear(Color(0.4f, 0.4f, 0.4f));
  scene.draw();
}

CINDER_APP_NATIVE( DowaProjectApp, RendererGl )
