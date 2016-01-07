#pragma once
#include "ViewGroup.h"
#include "ofxCv.h"
#include "../filter/AbstractFilter.h"

VIEW(CameraImageView){
	public:
		CameraImageView(ofImage* img,std::shared_ptr<View> foreground,std::shared_ptr<View> background);
		ofImage* image;
		ofImage outputImage;
		AbstractFilter* filter;
		void render() const;
		virtual void update();
		std::shared_ptr<View> foreground;
		std::shared_ptr<View> background;
		ofFbo backgroundFbo;
	private:
		ofRectangle imageContainer;
};
