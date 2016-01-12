#pragma once

#include "ofMain.h"
#include "View.h"

class RootView : public View {
	public:
		RootView();
		virtual ~RootView();
		
		virtual std::shared_ptr<View> addChild(std::shared_ptr<View> view);
		
		void onTouchDown(ofTouchEventArgs& onTouch);
		void onTouchUp(ofTouchEventArgs& onTouch);
		void onTouchMove(ofTouchEventArgs& onTouch);
		
		void onMouseDown(ofMouseEventArgs& onMouse);
		void onMouseUp(ofMouseEventArgs& onMouse);
		void onMouseMove(ofMouseEventArgs& onMouse);
		
		void onResized(ofResizeEventArgs& event);
		
		void onUpdate(ofEventArgs& event);
		void onRender(ofEventArgs& event);
		
		void eventBind();
		void eventUnBind();
};