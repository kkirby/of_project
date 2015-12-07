#include "ofApp.h"
#include "view/ViewGroup.h"
#include "view/ColoredRect.h"
#include "view/TextureView.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(34, 34, 34);
	ofSetVerticalSync(false);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofDisableArbTex();
	doShader = false;
	grabber.setDeviceID(0);
	grabber.setDesiredFrameRate(30);
	grabber.setup(400,300,true);
	//shader.load("shaders/noise.vert", "shaders/noise.frag");
	//cameraPlugin.setGrabber((ofxAndroidVideoGrabber*)grabber.getGrabber().get());
	ofSetCircleResolution(90);
	
	myView = ViewBuilder<ViewGroup>({
		{"fill",""},
		{"id","root"}
	})->addChild(
		ViewBuilder<ViewGroup>({
			{"top","0px"},
			{"height","25%"},
			{"fillX",""},
			{"id","top"}
		})->addChild(
			ViewBuilder<ColoredRect>({
				{"fill",""},
				{"id","ColorRect0"}
			},rand() % 256,rand() % 256,rand() % 256)
		),
		ViewBuilder<ViewGroup>({
			{"height","75%"},
			{"top","25%"},
			{"id","bottom"}
		})->addChild(
			ViewBuilder<ViewGroup>({
				{"right","25%"},
				{"top","0px"},
				{"bottom","0px"},
				{"left","0px"},
				{"id","left"}
			})->addChild(
				ViewBuilder<TextureView>({
					{"fill",""},
					{"id","textureView"}
				},&grabber.getTexture(),GL_RGB,0)
			),
			ViewBuilder<ViewGroup>({
				{"left","75%"},
				{"width","25%"},
				{"id","right"}
			})->addChild(
				ViewBuilder<ColoredRect>(
					{
						{"fillX",""},
						{"height","50px"},
						{"top","0px"},
						{"id","ColorRect1"}
					},
					rand() % 256,rand() % 256,rand() % 256
				),
				ViewBuilder<ColoredRect>(
					{
						{"fillX",""},
						{"height","50%"},
						{"top","50px"},
						{"id","ColorRect2"}
					},
					rand() % 256,rand() % 256,rand() % 256
				),
				ViewBuilder<ColoredRect>(
					{
						{"fillX",""},
						{"height","25%"},
						{"bottom","0px"},
						{"id","ColorRect3"}
					},
					rand() % 256,rand() % 256,rand() % 256
				)
			)
		)
	);
	ofRectangle container(0,0,ofGetWidth(),ofGetHeight());
	myView->recalculateWorld(container,container);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	/*updateCameraSize();


	fbo.begin();
	ofClear(255,255,255,0);
	ofTranslate(grabber.getWidth() / 2, grabber.getHeight() / 2);
	grabber.draw(0,0);
	fbo.end();


	if(doShader){
		shader.begin();
		shader.setUniform1f("gamma",(((float)mouseY / (float)ofGetHeight()) * 20.0) - 10);
	}

	ofPushMatrix();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	fbo.draw(0,0);
	ofPopMatrix();

	if(doShader){
		shader.end();
	}
	ofSetRectMode(OF_RECTMODE_CORNER);
	if(cameraPlugin.image.isAllocated()){
		ofPushMatrix();
		cameraPlugin.image.draw(0,0);
		ofPopMatrix();
	}*/
	myView->doRender();
	//grabber.draw(0,0);
}

void ofApp::updateCameraSize(){
	float grabberAspectRatio = grabber.getWidth() / grabber.getHeight();
	if(ofGetWidth() > ofGetHeight()){
		cameraWidth = ofGetHeight()*grabberAspectRatio;
		cameraHeight = ofGetHeight();
	}
	else {
		cameraWidth = ofGetWidth();
		cameraHeight = ofGetWidth()  * 1.0/grabberAspectRatio;
	}
	if(!fbo.isAllocated()){
		fbo.allocate(grabber.getWidth(),grabber.getHeight(),GL_RGB);
	}
}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

void ofApp::mousePressed(ofMouseEventArgs& touch){
	myView->uiDown(touch);
}

void ofApp::mouseReleased(ofMouseEventArgs& touch){
	myView->uiUp(touch);
}

void ofApp::touchDown(ofTouchEventArgs& touch){
	myView->uiDown(touch);
}

void ofApp::touchUp(ofTouchEventArgs& touch){
	myView->uiUp(touch);
}


//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
