#include "View.h"

View::View(){
	id = "Unnamed";
}

void View::recalculateWorld(const ofRectangle& container,const ofRectangle& viewport){
	ofRectangle newWorldRect = rect.getOfRect(container,viewport);
	if(newWorldRect != worldRect){
		worldRect = newWorldRect;
		update();
		for(auto& view : children){
			view->recalculateWorld(worldRect,viewport);
		}
	}
}

std::shared_ptr<View> View::getptr(){
	return this->shared_from_this();
}

std::shared_ptr<View> View::addChild(std::shared_ptr<View> view){
	children.push_back(view);
	return getptr();
}

void View::renderChildren() const {
	for(auto& child : children){
		child->render();
	}
}

void View::render() const {
	renderContent();
	renderChildren();
}

// TODO: handle events only if nothing is overlapping view
void View::uiDown(const ofVec2f& pt){
	for(auto& view : children){
		view->uiDown(pt);
	}
	if(interaction.onDown(worldRect,pt))onUiDown(pt);
}

void View::uiMove(const ofVec2f& pt){
	for(auto& view : children){
		view->uiMove(pt);
	}
	bool changed;
	bool res = interaction.onMove(worldRect,pt,&changed);
	if(changed){
		if(res)onUiDown(pt);
		else onUiUp(pt);
	}
}

void View::uiUp(const ofVec2f& pt){
	for(auto& view : children){
		view->uiUp(pt);
	}
	bool deactivate;
	bool res = interaction.onUp(worldRect,pt,&deactivate);
	if(deactivate)onUiUp(pt);
	if(res)onUiClicked(pt);
}