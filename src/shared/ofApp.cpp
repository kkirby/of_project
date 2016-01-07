#include "ofApp.h"
#include "view/ColoredRect.h"
#include "view/TextureView.h"
#include "CameraImageView.h"
#include "view/ImageView.h"
#include "view/ButtonView.h"

#include "ffmpeg/ffmpeg.h"
#include <future>

#ifdef TARGET_ANDROID
#include "android/Util.h"
#define INPUT_FILE "/mnt/sdcard/untitled2.mp4"
#define OUTPUT_FILE "/mnt/sdcard/untitled3.mp4"
#else
#define INPUT_FILE "/Users/kkirbatski/Desktop/Untitled.mov"
#define OUTPUT_FILE "/Users/kkirbatski/Desktop/Untitled2.mp4"
#endif

void ofApp::do_ffmpeg_stuff(){
	do_ffmpeg(
		{
			"-i",
			INPUT_FILE,
			"-strict",
			"-2",
			"-vf",
			"crop=in_h",
			OUTPUT_FILE
		},
		[](double progress){
			ofLogVerbose("Progress") << progress;
		},
		[](void* ptr,int level,const char* fmt,va_list args){
			char message[1024];
			vsnprintf(message,1024,fmt,args);
			ofLogVerbose("Message") << message;
		}
	);
}

void ofApp::setup(){
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofDisableArbTex();
	grabber.setDeviceID(1);
	grabber.setDesiredFrameRate(30);
	//grabber.setup(1440,1088,true);
	grabber.setup(640,480,true);
	overlay.load("overlay2.png");
	#if defined (TARGET_ANDROID)
		//cameraPlugin.setGrabber((ofxAndroidVideoGrabber*)grabber.getGrabber().get());
		orientation = ((ofxAndroidVideoGrabber*)grabber.getGrabber().get())->getCameraOrientation();
	#endif
	fbo.allocate(grabber.getWidth(),grabber.getHeight(),GL_RGB);
	myView = ViewBuilder<RootView>({
		{"fill",""},
		{"id","root"}
	})->addChild(
		ViewBuilder<CameraImageView>(
			{{"fill",""}},
			&overlay,
			ViewBuilder<TextureView>({
				{"fill",""},
				{"id","textureView"}
			},&fbo.getTexture(),GL_RGB,0),
			ViewBuilder<TextureView>({
				{"fill",""},
				{"id","textureView"}
			},&fbo.getTexture(),GL_RGB,0)
		)
	)->addChild(
		ViewBuilder<ButtonView>(
			{
				{"id","Button"},
				{"right","10px"},
				{"top","10px"},
				{"width","341px"},
				{"height","341px"}
			},
			ViewBuilder<ImageView>(
				{
					{"fill",""}
				},
				"btn.png"
			),
			ViewBuilder<ImageView>(
				{
					{"fill",""}
				},
				"btn_down.png"
			),
			[](){
				ofLogVerbose("ClickAction") << "Clicked!";
			}
		)
	)->addChild(
		ViewBuilder<ColoredRect>(
			{
				{"id","Colored"},
				{"top","10px"},
				{"left","10px"},
				{"width","100px"},
				{"height","100px"}
			},
			10,10,10
		)
	)->addChild(
		ViewBuilder<ColoredRect>(
			{
				{"top","130px"},
				{"left","130px"},
				{"width","100px"},
				{"height","100px"}
			},
			20,20,20	
		)
	);
}

void ofApp::update(){
	grabber.update();
	if(!grabber.isFrameNew())return;
	
	int rotation;
	#if defined TARGET_ANDROID
		rotation = (androidUtil::getDeviceRotation() + orientation) % 360;
	#else
		rotation = ofGetUnixTime() % 4;
		if(rotation == 0)rotation = 0;
		else if(rotation == 1)rotation = 90;
		else if(rotation == 2)rotation = 180;
		else if(rotation == 3)rotation = 270;
	#endif
	int width = grabber.getWidth();
	int height = grabber.getHeight();
	
	if(rotation == 90 || rotation == 270){
		int temp = width;
		width = height;
		height = temp;
	}
	if(!fbo.isAllocated() || fbo.getWidth() != width || fbo.getHeight() != height){
		fbo.allocate(width,height,GL_RGB);
	}

	fbo.begin();
	ofClear(255,255,255,0);
	ofPushMatrix();
	ofTranslate(width / 2,height / 2);
	ofRotate(rotation,0,0,1);
	ofPushMatrix();
	if(rotation == 0){
		grabber.draw(-1 * width / 2,-1 * height / 2);
	}
	else if(rotation == 90){
		grabber.draw(-1 * height / 2,-1 * width / 2);
	}
	else if(rotation == 180){
		grabber.draw(-1 * width / 2,-1 * height / 2);
	}
	else if(rotation == 270){
		grabber.draw(-1 * height / 2,-1 * width / 2);
	}
	ofPopMatrix();
	ofPopMatrix();
	fbo.end();
}

void ofApp::draw(){
	myView->render();
}