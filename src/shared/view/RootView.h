#pragma once

#include "ofMain.h"
#include "View.h"

VIEW(RootView){
	public:
		RootView();
		
		virtual std::shared_ptr<View> addChild(std::shared_ptr<View> view);
		
		void touchDown(ofTouchEventArgs& touch);
		void touchUp(ofTouchEventArgs& touch);
		void touchMove(ofTouchEventArgs& touch);
		
		void mouseDown(ofMouseEventArgs& mouse);
		void mouseUp(ofMouseEventArgs& mouse);
		void mouseMove(ofMouseEventArgs& mouse);
		
		void resized(ofResizeEventArgs& event);
};