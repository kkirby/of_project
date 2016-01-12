#pragma once

#include "View.h"
#include <memory>
#include <functional>

enum class ButtonState {
	DOWN,
	UP
};

class ButtonView : public View {
	public:
		ButtonView(std::shared_ptr<View> up,std::shared_ptr<View> down,std::function<void()> action);
		ButtonState state;
		std::shared_ptr<View> up;
		std::shared_ptr<View> down;
		std::function<void()> action;
		virtual void onUiClicked(const ofVec2f& touch);
		virtual void onUiDown(const ofVec2f& touch);
		virtual void onUiUp(const ofVec2f& touch);
		virtual void rectUpdated();
		virtual void renderContent() const;
		virtual void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);		
};