#include "ColoredRect.h"

ColoredRect::ColoredRect(int r,int g,int b): r(r), g(g), b(b) {}

void ColoredRect::renderContent() const {
	ofPushStyle();
	ofSetColor(r,g,b);
	ofFill();
	ofDrawRectangle(worldRect);
	ofPopStyle();
}

void ColoredRect::onUiUp(const ofVec2f& touch){
	r = 60;
	g = 200;
	b = 120;
}

void ColoredRect::onUiDown(const ofVec2f& touch){
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
}

void ColoredRect::onUiClicked(const ofVec2f& touch){
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
}