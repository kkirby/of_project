#pragma once

#include "ofMain.h"
#include "ViewGroup.h"

VIEW(RootView){
	public:
		RootView();
	
		std::shared_ptr<ViewGroup> group;
		
		std::shared_ptr<RootView> addChild(std::shared_ptr<View> view);
		
		void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		
		virtual void render() const;
		
		virtual void uiDown(const ofVec2f& pt);
		virtual void uiUp(const ofVec2f& pt);
		virtual void uiMove(const ofVec2f& pt);
		
		void touchDown(ofTouchEventArgs& touch);
		void touchUp(ofTouchEventArgs& touch);
		void touchMove(ofTouchEventArgs& touch);
		
		void mouseDown(ofMouseEventArgs& mouse);
		void mouseUp(ofMouseEventArgs& mouse);
		void mouseMove(ofMouseEventArgs& mouse);
		
		void resized(ofResizeEventArgs& event);
};