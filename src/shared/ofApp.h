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

#include "ofxStateMachine.h"
#include "SharedData.h"

class ofApp : public ofBaseApp {
	
	public:
		void setup();
		itg::ofxStateMachine<SharedData> stateMachine;
};