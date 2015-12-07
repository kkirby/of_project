#include "ofMain.h"
#include "ofApp.h"

extern "C" {
	int of_project_main(){
		//ofGLESWindowSettings settings;
		//settings.setGLESVersion(2);
		//ofCreateWindow(settings);
		ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context

		// this kicks off the running of my app
		// can be OF_WINDOW or OF_FULLSCREEN
		// pass in width and height too:
		ofRunApp( new ofApp() );
		return 0;
	}

#if defined (TARGET_ANDROID)
	int Java_cc_openframeworks_OFAndroid_init(){
		return of_project_main();
	}
#endif

#if defined (TARGET_OSX)
	int main(){
		return of_project_main();
	}
#endif
}
