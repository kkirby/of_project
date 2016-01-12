#include "CameraImageView.h"
#include "filter/GaussianBlurFilter.h"
#include "filter/BrightnessFilter.h"
#include "filter/GroupFilter.h"
#include "util/size.h"

CameraImageView::CameraImageView(
	ofImage* img
) : image(img), camera(0,30), forceCameraRender(false) {
	GroupFilter* groupFilter = new GroupFilter();
	groupFilter->push_back(new GaussianBlurFilter());
	groupFilter->push_back(new BrightnessFilter(-0.25));
	filter = groupFilter;
}

void CameraImageView::rectUpdated(){
	imageContainer.set(0,0,image->getWidth(),image->getHeight());
	imageContainer.scaleTo(
		worldRect,
		util::size(imageContainer) > util::size(worldRect) ?
			OF_SCALEMODE_FIT :
			OF_SCALEMODE_CENTER
	);
	
	outputImage.allocate(imageContainer.width,imageContainer.height,OF_IMAGE_COLOR_ALPHA);
	cv::Mat imageCv = ofxCv::toCv(*image);
	cv::Mat mutableImage = ofxCv::toCv(outputImage);
	ofxCv::resize(imageCv,mutableImage,cv::INTER_AREA);
	outputImage.update();
	
	backgroundFbo.allocate(worldRect.width,worldRect.height);
	foregroundFbo.allocate(imageContainer.width,imageContainer.height);
	camera.refresh();
	forceCameraRender = true;
}

void CameraImageView::update(){
	camera.update();
	if(forceCameraRender || camera.isFrameNew()){
		ofRectangle source;
		ofRectangle target;
		
		forceCameraRender = false;
		
		backgroundFbo.begin();
			ofClear(0,0,0,0);
		
			source.set(0,0,camera.getWidth(),camera.getHeight());
			target.set(0,0,backgroundFbo.getWidth(),backgroundFbo.getHeight());
			source.scaleTo(target,OF_SCALEMODE_FILL);
		
			filter->begin();
				camera.draw(source);
			filter->end();
		
		backgroundFbo.end();
		
		foregroundFbo.begin();
			ofClear(0,0,0,0);
			source.set(0,0,camera.getWidth(),camera.getHeight());
			target.set(0,0,foregroundFbo.getWidth(),foregroundFbo.getHeight());
			source.scaleTo(target,OF_SCALEMODE_FILL);
			camera.draw(source);
		foregroundFbo.end();
	}
}

void CameraImageView::renderContent() const {
	backgroundFbo.draw(worldRect);
	foregroundFbo.draw(imageContainer);
	
	ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	image->draw(imageContainer);
	ofPopStyle();
}