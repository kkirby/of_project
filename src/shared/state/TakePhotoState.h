#pragma once

#include "ofxState.h"
#include "sharedData.h"
#include "View.h"
#include "Camera.h"

class TakePhotoState : public itg::ofxState<SharedData> {
	public:
		TakePhotoState();
		std::shared_ptr<View> view;
		virtual void setup();
		string getName();
	protected:
		ofVideoGrabber grabber;
		ofImage overlay;
		ofFbo fbo;
};