#include "RootView.h"
#include "ViewBuilder.h"

RootView::RootView(){
	ofAddListener(ofEvents().touchUp, this, &RootView::touchUp);
	ofAddListener(ofEvents().touchDown, this, &RootView::touchDown);
	ofAddListener(ofEvents().touchMoved, this, &RootView::touchMove);
	
	ofAddListener(ofEvents().mouseReleased, this, &RootView::mouseUp);
	ofAddListener(ofEvents().mousePressed, this, &RootView::mouseDown);
	ofAddListener(ofEvents().mouseDragged, this, &RootView::mouseMove);
	
	ofAddListener(ofEvents().windowResized, this, &RootView::resized);
	
	ofResizeEventArgs resizeEvent(ofGetWidth(),ofGetHeight());
	resized(resizeEvent);
}

void RootView::resized(ofResizeEventArgs& event){
	ofRectangle container(0,0,event.width,event.height);
	recalculateWorld(container,container);
}

std::shared_ptr<View> RootView::addChild(std::shared_ptr<View> view){
	View::addChild(view);
	view->recalculateWorld(worldRect,worldRect);
	return getptr();
}

//------

void RootView::touchDown(ofTouchEventArgs& touch){
	uiDown(touch);
}

void RootView::touchUp(ofTouchEventArgs& touch){
	uiUp(touch);
}

void RootView::touchMove(ofTouchEventArgs& touch){
	uiMove(touch);
}

void RootView::mouseDown(ofMouseEventArgs& mouse){
	uiDown(mouse);
}

void RootView::mouseUp(ofMouseEventArgs& mouse){
	uiUp(mouse);
}

void RootView::mouseMove(ofMouseEventArgs& mouse){
	uiMove(mouse);
}