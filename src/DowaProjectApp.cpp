
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "device/Device.hpp"
#include "scene/Scene.hpp"
#include "scene/SceneManager.hpp"
#include "resource/Resource.hpp"

using namespace ci;
using namespace ci::app;
using namespace dowa;

class DowaProjectApp : public AppNative {
private:

public:

	//Add Code----------------
	static const int
		TEXTURE_WIDTH = 568,
		TEXTURE_HEIGHT = 320;
	//------------------------

	void setup();

	void prepareSettings(Settings* settings) {
		settings->disableFrameRate();

		//Add Code----------------
		settings->setWindowSize(TEXTURE_WIDTH, TEXTURE_HEIGHT);
		settings->setResizable(false);
		//------------------------
	}

	void mouseDown(MouseEvent event);
	void touchesBegan(TouchEvent event);
	void update();
	void draw();
};

void DowaProjectApp::setup() {
#if defined(CINDER_COCOA_TOUCH)
	//getSignalSupportedOrientations().connect([]() {
	//  return InterfaceOrientation::LandscapeLeft | InterfaceOrientation::LandscapeRight;
	//});
#endif

	Device::enable();
	AudioManager::enable();
	TextureManager::enable();
	SceneManager::enable();
	SceneManager::create(SceneType::CinderellaLoad);
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

CINDER_APP_NATIVE(DowaProjectApp, RendererGl)
