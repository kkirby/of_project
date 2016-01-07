#include "ofMain.h"
#include "ofApp.h"

int of_project_main(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	#ifdef TARGET_ANDROID
	ofGLESWindowSettings settings;
	settings.setGLESVersion(2);
	ofCreateWindow(settings);
	#else
	ofGLWindowSettings settings;
	settings.setGLVersion(2,1);
	settings.height = settings.width = 600;
	ofCreateWindow(settings);
	#endif
	ofRunApp( new ofApp() );
	return 0;
}

#if defined (TARGET_ANDROID)

extern "C" int Java_cc_openframeworks_OFAndroid_init(){
	return of_project_main();
}
	
#elif defined (TARGET_OSX)
int main(){
	of_project_main();
	return 0;
}
#endif