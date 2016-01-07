#pragma once

#include <ofMain.h>

#if defined (TARGET_ANDROID)

#include "ofxAndroidVideoGrabber.h"
#include "javaClass.h"

class CameraPlugin : public JavaClass {
	public:
		CameraPlugin();
		void setGrabber(ofxAndroidVideoGrabber* grabber);
		void takePhoto();
		void startRecording();
		void stopRecording();
		jobject instance;
		ofImage image;
		bool hasImage;
		bool recording;
};

#endif