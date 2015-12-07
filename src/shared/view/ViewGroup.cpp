#include "ViewGroup.h"

ViewGroup::ViewGroup(): children(0) {}

void ViewGroup::recalculateWorld(const ofRectangle& container,const ofRectangle& viewport){
	View::recalculateWorld(container,viewport);
	for(auto& view : children){
		view->recalculateWorld(worldRect,viewport);
	}
}

void ViewGroup::render(const ofRectangle& container){
	for(auto& view : children){
		view->doRender();
	}
}

ViewGroup::selfptr_t ViewGroup::addChild(std::shared_ptr<View> view){
	children.push_back(view);
	return getptr();
}
	
void ViewGroup::onUiDown(ofVec2f& touch){
	for(auto& view : children){
		view->uiDown(touch);
	}
}

void ViewGroup::onUiUp(ofVec2f& touch){
	for(auto& view : children){
		view->uiUp(touch);
	}
}