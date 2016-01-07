#include "ButtonView.h"

ButtonView::ButtonView(
	std::shared_ptr<View> up,
	std::shared_ptr<View> down,
	std::function<void()> action
): up(up), down(down), action(action), state(ButtonState::UP) {}

void ButtonView::onUiClicked(const ofVec2f& touch){
	if(action){
		action();
	}
}

void ButtonView::onUiDown(const ofVec2f& touch){
	state = ButtonState::DOWN;
}

void ButtonView::onUiUp(const ofVec2f& touch){
	state = ButtonState::UP;
}

void ButtonView::update(){
	up->update();
	down->update();
}

void ButtonView::recalculateWorld(const ofRectangle& container,const ofRectangle& viewport){
	View::recalculateWorld(container,viewport);
	up->recalculateWorld(worldRect,viewport);
	down->recalculateWorld(worldRect,viewport);
}

void ButtonView::render() const {
	if(state == ButtonState::UP){
		up->render();
	}
	else if(state == ButtonState::DOWN){
		down->render();
	}
}
