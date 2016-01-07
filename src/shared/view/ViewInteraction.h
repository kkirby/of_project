#pragma once

#include "ofMain.h"

class ViewInteraction {
	public:
		bool isActive;
		bool hasFocus;
		
		ViewInteraction();
		
		bool onDown(const ofRectangle& worldRect,const ofVec2f& touch);
		bool onUp(const ofRectangle& worldRect,const ofVec2f& touch,bool* const deactivate);
		bool onMove(const ofRectangle& worldRect,const ofVec2f& touch,bool* const changed);
		
		bool isEventTarget(const ofRectangle& worldRect,const ofVec2f& touch) const;
};