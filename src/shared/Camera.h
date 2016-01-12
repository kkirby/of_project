#pragma once
#include <memory>
#include "ofMain.h"

#ifdef TARGET_ANDROID
#include "androidUtil.h"
#include "CameraPlugin.h"
#endif

class Camera : public ofBaseDraws {
	public:
		ofVideoGrabber grabber;
		OF_VID_GRABBER_TYPE* rootGrabber;
		ofFbo fbo;
		int rotation;
		#ifdef TARGET_ANDROID
		CameraPlugin cameraPlugin;
		#endif
	
		Camera(int deviceId,int fps);
		bool isFrameNew() const;
		void update();
		void refresh();
		virtual void draw(float x, float y) const;
	    virtual void draw(float x, float y, float w, float h) const;
		virtual void draw(const ofRectangle & rect) const;
		virtual void draw(const ofPoint & point, float w, float h) const;
		virtual float getHeight() const;
		virtual float getWidth() const;
		
	protected:
		void drawGrabberToFboRotated() const;
		void applyRotationToFbo();
		
};