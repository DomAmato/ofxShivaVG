#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofGLFWWindowSettings settings;
	settings.stencilBits = 8;
	settings.glVersionMajor = 2;
	settings.glVersionMinor = 1;

	auto window = ofCreateWindow(settings);
	auto app = make_shared<ofApp>();
	ofRunApp(window, app);

	return ofRunMainLoop();
}
