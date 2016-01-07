#pragma once
#include "ofxCv.h"
#include "../filter/AbstractFilter.h"
#include "View.h"

VIEW(CameraImageView){
	public:
		CameraImageView(ofImage* img,std::shared_ptr<View> foreground,std::shared_ptr<View> background);
		ofImage* image;
		ofImage outputImage;
		AbstractFilter* filter;
		void renderContent() const;
		virtual void update();
		std::shared_ptr<View> foreground;
		std::shared_ptr<View> background;
		ofFbo backgroundFbo;
	private:
		ofRectangle imageContainer;
};
