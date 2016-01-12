#include "RootView.h"
#include "ViewBuilder.h"

RootView::RootView(){
	eventBind();
	ofResizeEventArgs resizeEvent(ofGetWidth(),ofGetHeight());
	onResized(resizeEvent);
}

RootView::~RootView(){
	eventUnBind();
}

void RootView::eventBind(){
	ofAddListener(ofEvents().touchUp, this, &RootView::onTouchUp);
	ofAddListener(ofEvents().touchDown, this, &RootView::onTouchDown);
	ofAddListener(ofEvents().touchMoved, this, &RootView::onTouchMove);
	
	ofAddListener(ofEvents().mouseReleased, this, &RootView::onMouseUp);
	ofAddListener(ofEvents().mousePressed, this, &RootView::onMouseDown);
	ofAddListener(ofEvents().mouseDragged, this, &RootView::onMouseMove);
	
	ofAddListener(ofEvents().windowResized, this, &RootView::onResized);
	
	ofAddListener(ofEvents().update, this, &RootView::onUpdate);
	ofAddListener(ofEvents().draw, this, &RootView::onRender);
}

void RootView::eventUnBind(){
	ofRemoveListener(ofEvents().touchUp, this, &RootView::onTouchUp);
	ofRemoveListener(ofEvents().touchDown, this, &RootView::onTouchDown);
	ofRemoveListener(ofEvents().touchMoved, this, &RootView::onTouchMove);
	
	ofRemoveListener(ofEvents().mouseReleased, this, &RootView::onMouseUp);
	ofRemoveListener(ofEvents().mousePressed, this, &RootView::onMouseDown);
	ofRemoveListener(ofEvents().mouseDragged, this, &RootView::onMouseMove);
	
	ofRemoveListener(ofEvents().windowResized, this, &RootView::onResized);
	
	ofRemoveListener(ofEvents().update, this, &RootView::onUpdate);
	ofRemoveListener(ofEvents().draw, this, &RootView::onRender);
}

void RootView::onUpdate(ofEventArgs& event){
	update();
}

void RootView::onRender(ofEventArgs& event){
	render();
}

void RootView::onResized(ofResizeEventArgs& event){
	ofRectangle container(0,0,event.width,event.height);
	recalculateWorld(container,container);
}

std::shared_ptr<View> RootView::addChild(std::shared_ptr<View> view){
	View::addChild(view);
	view->recalculateWorld(worldRect,worldRect);
	return getptr();
}

//------

void RootView::onTouchDown(ofTouchEventArgs& touch){
	uiDown(touch);
}

void RootView::onTouchUp(ofTouchEventArgs& touch){
	uiUp(touch);
}

void RootView::onTouchMove(ofTouchEventArgs& touch){
	uiMove(touch);
}

void RootView::onMouseDown(ofMouseEventArgs& mouse){
	uiDown(mouse);
}

void RootView::onMouseUp(ofMouseEventArgs& mouse){
	uiUp(mouse);
}

void RootView::onMouseMove(ofMouseEventArgs& mouse){
	uiMove(mouse);
}