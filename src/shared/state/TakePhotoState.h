#pragma once

#include "ofxState.h"
#include "sharedData.h"

class TakePhotoState : public itg::ofxState<SharedData> {
	public:
		virtual void setup();
		virtual void update();
		virtual void draw();
};