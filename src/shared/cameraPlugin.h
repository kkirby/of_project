#pragma once

#if defined (TARGET_ANDROID)

#include "ofxAndroidVideoGrabber.h"
#include "javaClass.h"

class CameraPlugin : public JavaClass {
	public:
		CameraPlugin();
		void setGrabber(ofxAndroidVideoGrabber* grabber);
		void takePhoto();
		jobject instance;
		ofImage image;
		bool hasImage;
};

#endif