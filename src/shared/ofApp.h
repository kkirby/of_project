#pragma once

#include "ofMain.h"
#include "ofBaseApp.h"
#include "view/ViewBuilder.h"

#if defined (TARGET_ANDROID)
#include "ofxAndroid.h"
#include "ofxAndroidVideoGrabber.h"
#endif

#if defined (TARGET_IOS)
#include "ofxiOS.h"
#include "ofxiOSVideoGrabber.h"
#endif

#include "cameraPlugin.h"
#include "ViewGroup.h"

class ofApp : public ofBaseApp {
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void windowResized(int w, int h);

		void mousePressed(ofMouseEventArgs& touch);
		void mouseReleased(ofMouseEventArgs& touch);
		void touchDown(ofTouchEventArgs& touch);
		void touchUp(ofTouchEventArgs& touch);

		void pause();
		void stop();
		void resume();
		void reloadTextures();

		bool backPressed();
		void okPressed();
		void cancelPressed();
		
		void updateCameraSize();

		ofVideoGrabber grabber;
		bool doShader;
		ofShader shader;
		ofImage image;
		ofPlanePrimitive plane;
		ofFbo fbo;
		
		size_t cameraWidth;
		size_t cameraHeight;
		
		//CameraPlugin cameraPlugin;
		std::shared_ptr<ViewGroup> myView;
};