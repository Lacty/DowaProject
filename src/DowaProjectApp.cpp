#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DowaProjectApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void DowaProjectApp::setup()
{
}

void DowaProjectApp::mouseDown( MouseEvent event )
{
}

void DowaProjectApp::update()
{
}

void DowaProjectApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( DowaProjectApp, RendererGl )
