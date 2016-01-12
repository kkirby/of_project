#pragma once
#include "ofxCv.h"
#include "../filter/AbstractFilter.h"
#include "View.h"
#include "Camera.h"

class CameraImageView : public View {
	public:
		CameraImageView(ofImage* img);
		ofImage* image;
		ofImage outputImage;
		AbstractFilter* filter;
		void renderContent() const;
		virtual void rectUpdated();
		ofFbo backgroundFbo;
		ofFbo foregroundFbo;
		Camera camera;
		virtual void update();
	private:
		ofRectangle imageContainer;
		bool forceCameraRender;
};
