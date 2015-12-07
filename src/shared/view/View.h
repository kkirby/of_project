#pragma once

#include "ViewRect.h"
#include "ofMain.h"
#include <memory>

class View {
	public:
		ViewRect rect;
		const char* id;
		View();
		
		ofRectangle worldRect;
		
		virtual void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		void doRender();
		virtual void render(const ofRectangle& container) = 0;
		
		bool isEventTarget(ofVec2f& touch);
		
		virtual void uiDown(ofVec2f& touch);
		virtual void uiUp(ofVec2f& touch);
			
		virtual void onUiDown(ofVec2f& touch){}
		virtual void onUiUp(ofVec2f& touch){}
};