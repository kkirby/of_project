#pragma once

#include "ofMain.h"
#include "ofBaseApp.h"
#include "view/ViewBuilder.h"

#if defined (TARGET_ANDROID)
#include "ofxAndroid.h"
#include "ofxAndroidVideoGrabber.h"
#include "../android/cameraPlugin.h"
#endif

#if defined (TARGET_IOS)
#include "ofxiOS.h"
#include "ofxiOSVideoGrabber.h"
#endif

#include "ViewGroup.h"

class ofApp : public ofBaseApp {
	
	public:
		
		void setup();
		void update();
		void draw();

		void mousePressed(ofMouseEventArgs& touch);
		void mouseReleased(ofMouseEventArgs& touch);
		void mouseDragged(ofMouseEventArgs& touch);
		void touchDown(ofTouchEventArgs& touch);
		void touchUp(ofTouchEventArgs& touch);
		
		void windowResized(int w, int h);
		
		void do_ffmpeg_stuff();

		ofVideoGrabber grabber;
		ofImage overlay;
		ofFbo fbo;
		size_t orientation;
		
#if defined (TARGET_ANDROID)		
		CameraPlugin cameraPlugin;
#endif
		std::shared_ptr<View> myView;
};