#include "ColoredRect.h"

ColoredRect::ColoredRect(int r,int g,int b): r(r), g(g), b(b) {}

void ColoredRect::render(const ofRectangle& container){
	ofPushStyle();
	ofSetColor(r,g,b);
	ofFill();
	ofDrawRectangle(container);
	ofPopStyle();
}

void ColoredRect::onUiUp(ofVec2f& touch){
	r = rand() % 256;
	g = rand() % 256;
	b = rand() % 256;
}