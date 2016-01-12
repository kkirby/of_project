#include "ofApp.h"
#include "TakePhotoState.h"

void ofApp::setup(){
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofDisableArbTex();
	
	stateMachine.addState<TakePhotoState>();
	stateMachine.changeState("takePhotoState");
}