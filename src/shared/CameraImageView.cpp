#include "CameraImageView.h"
#include "../filter/GaussianBlurFilter.h"
#include "../filter/BrightnessFilter.h"
#include "../filter/GroupFilter.h"
#include "../size.h"

CameraImageView::CameraImageView(
	ofImage* img,std::shared_ptr<View> _foreground,std::shared_ptr<View> _background
) : image(img),foreground(_foreground),background(_background){
	/*GroupFilter* groupFilter = new GroupFilter();
	groupFilter->push_back(new GaussianBlurFilter());
	groupFilter->push_back(new BrightnessFilter(-0.25));
	filter = groupFilter;*/
}

void CameraImageView::update(){
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
	
	background->recalculateWorld(worldRect,worldRect);
	foreground->recalculateWorld(imageContainer,imageContainer);
}

void CameraImageView::render() const {
	//filter->begin();
	//background->render();
	//filter->end();
	
	foreground->render();
	
	ofPushStyle();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	image->draw(imageContainer);
	ofPopStyle();
}