#include "View.h"

View::View(){
	id = "Unnamed";
}

void View::recalculateWorld(const ofRectangle& container,const ofRectangle& viewport){
	ofLogVerbose("View") << "ID(" << id << ") recalulateworld";
	worldRect = rect.getOfRect(container,viewport);
	ofLogVerbose("View") << "ID(" << id << ") " << worldRect.getX() << "/" << worldRect.getY() << " " << worldRect.getWidth() << "x" << worldRect.getHeight();
}

void View::doRender(){
	render(worldRect);
}

bool View::isEventTarget(ofVec2f& touch){
	return worldRect.inside(touch.x,touch.y);
}

void View::uiDown(ofVec2f& touch){
	if(isEventTarget(touch))onUiDown(touch);
}

void View::uiUp(ofVec2f& touch){
	if(isEventTarget(touch))onUiUp(touch);
}