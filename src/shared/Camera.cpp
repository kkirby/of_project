#include "Camera.h"
#include <cmath>

Camera::Camera(int deviceId,int fps) : rotation(0){
	rootGrabber = (OF_VID_GRABBER_TYPE*)grabber.getGrabber().get();
	grabber.setDeviceID(deviceId);
	grabber.setDesiredFrameRate(fps);
	float width = 640;
	float height = 480;
	#ifdef TARGET_ANDROID
	width = 960;
	height = 720;
	cameraPlugin.setGrabber(rootGrabber);
	#endif
	grabber.setup(width,height,true);
	refresh();
}

bool Camera::isFrameNew() const {
	return grabber.isFrameNew();
}

void Camera::refresh(){
	rotation = 270;
	#ifdef TARGET_ANDROID
		rotation = (360 + (
			androidUtil::getDeviceRotation() -
			rootGrabber->getCameraOrientation(0)
		)) % 360;
	#endif
	applyRotationToFbo();
}

void Camera::update(){
	grabber.update();
	if(!isFrameNew())return;
	drawGrabberToFboRotated();
}

void Camera::draw(float x, float y) const {
	draw(x,y,getWidth(),getHeight());
}

void Camera::draw(float x,float y,float w,float h) const {
	fbo.draw(x,y,w,h);
}

void Camera::draw(const ofRectangle & rect) const {
	draw(rect.x, rect.y, rect.width, rect.height);
}

void Camera::draw(const ofPoint & point, float w, float h) const {
	draw(point.x, point.y, w, h);
}

float Camera::getHeight() const {
	return fbo.getHeight();
}

float Camera::getWidth() const {
	return fbo.getWidth();
}

void Camera::applyRotationToFbo(){
	float width = grabber.getWidth();
	float height = grabber.getHeight();
	
	if(rotation == 90 || rotation == 270){
		float temp = width;
		width = height;
		height = temp;
	}
	if(!fbo.isAllocated() || fbo.getWidth() != width || fbo.getHeight() != height){
		fbo.allocate(width,height,GL_RGB);
	}
}

void Camera::drawGrabberToFboRotated() const {
	float width = fbo.getWidth();
	float height = fbo.getHeight();
	fbo.begin();
	ofClear(255,255,255,255);
	ofPushMatrix();
	ofTranslate(width / 2,height / 2);
	ofRotate(rotation,0,0,1);
	ofPushMatrix();
	if(rotation == 0 || rotation == 180){
		grabber.draw(
			width / 2,
			-1 * height / 2,
			-1 * width,
			height
		);
	}
	else if(rotation == 90 || rotation == 270){
		grabber.draw(
			-1 * height / 2,
			width / 2,
			height,
			-1 * width
		);
	}
	ofPopMatrix();
	ofPopMatrix();
	fbo.end();
}