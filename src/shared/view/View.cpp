#include "View.h"

View::View(){
	id = "Unnamed";
}

void View::recalculateWorld(const ofRectangle& container,const ofRectangle& viewport){
	ofRectangle newWorldRect = rect.getOfRect(container,viewport);
	if(newWorldRect != worldRect){
		worldRect = newWorldRect;
		update();
	}
}


// TODO: handle events only if nothing is overlapping view
void View::uiDown(const ofVec2f& touch){
	if(interaction.onDown(worldRect,touch))onUiDown(touch);
}

void View::uiMove(const ofVec2f& touch){
	bool changed;
	bool res = interaction.onMove(worldRect,touch,&changed);
	if(changed){
		if(res)onUiDown(touch);
		else onUiUp(touch);
	}
}

void View::uiUp(const ofVec2f& touch){
	bool deactivate;
	bool res = interaction.onUp(worldRect,touch,&deactivate);
	if(deactivate)onUiUp(touch);
	if(res)onUiClicked(touch);
}