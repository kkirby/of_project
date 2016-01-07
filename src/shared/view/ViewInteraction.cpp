#include "ViewInteraction.h"

ViewInteraction::ViewInteraction(): isActive(false), hasFocus(false) {
	
}

bool ViewInteraction::onDown(const ofRectangle& worldRect,const ofVec2f& touch){
	return isActive = hasFocus = isEventTarget(worldRect,touch);
}

bool ViewInteraction::onMove(const ofRectangle& worldRect,const ofVec2f& touch,bool* const changed){
	bool oldFocus = hasFocus;
	if(isActive){
		hasFocus = isEventTarget(worldRect,touch);
	}
	*changed = oldFocus != hasFocus;
	return isActive && hasFocus;
}

bool ViewInteraction::onUp(const ofRectangle& worldRect,const ofVec2f& touch,bool* const deactivate){
	bool ret = isActive && hasFocus;
	*deactivate = isActive;
	isActive = false;
	hasFocus = false;
	return ret;
}

bool ViewInteraction::isEventTarget(const ofRectangle& worldRect,const ofVec2f& touch) const {
	return worldRect.inside(touch.x,touch.y);
}