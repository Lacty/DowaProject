
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "device/Device.hpp"

#include "scene/Scene.hpp"
#include "scene/SceneManager.hpp"

#include "resource/ResourceManager.hpp"

using namespace ci;
using namespace ci::app;
using namespace dowa;

class DowaProjectApp : public AppNative {
private:
  
public:
  void setup();
  
  void prepareSettings(Settings* settings) {
    settings->disableFrameRate();
  }
  
  void mouseDown(MouseEvent event);
  void touchesBegan(TouchEvent event);
  void update();
  void draw();
};

void DowaProjectApp::setup() {
  getSignalSupportedOrientations().connect([]() {
    return InterfaceOrientation::LandscapeLeft | InterfaceOrientation::LandscapeRight;
  });

  Device::enable();
  //dowa::ResourceManager::enable();
  SceneManager::enable();
  SceneManager::create(SceneType::Test);
}

void DowaProjectApp::mouseDown(MouseEvent event) {
  Device::setTouchState(true, event.getPos());
}

void DowaProjectApp::touchesBegan(TouchEvent event) {
  Vec2f pos;
  for (auto& touch : event.getTouches()) {
    pos = touch.getPos();
    break;
  }
  Device::setTouchState(true, pos);
}

void DowaProjectApp::update() {
  SceneManager::update();
}

void DowaProjectApp::draw() {
	gl::clear(Color(0.4f, 0.4f, 0.4f));
  SceneManager::draw();
  Device::setTouchState(false, Vec2f::zero());
}

CINDER_APP_NATIVE( DowaProjectApp, RendererGl )
