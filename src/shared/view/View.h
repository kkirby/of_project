#pragma once

#include "ofMain.h"
#include "ViewRect.h"
#include "SharedView.h"
#include "../macros.h"
#include "ViewInteraction.h"

#define VIEW2(name,parent) class name : public SharedView<name>, public parent
#define VIEW1(name) VIEW2(name,View)
#define VIEW(...) VFUNC(VIEW, __VA_ARGS__)

class View {
	public:
		ViewRect rect;
		const char* id;
		View();
		
		ViewInteraction interaction;
		
		ofRectangle worldRect;
		
		virtual void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		
		virtual void update(){}
		
		virtual void render() const = 0;
		
		virtual void uiDown(const ofVec2f& touch);
		virtual void uiUp(const ofVec2f& touch);
		virtual void uiMove(const ofVec2f& touch);
			
		virtual void onUiDown(const ofVec2f& touch){}
		virtual void onUiUp(const ofVec2f& touch){}
		virtual void onUiMove(const ofVec2f& touch){}
		virtual void onUiClicked(const ofVec2f& touch){}
};