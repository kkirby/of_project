#pragma once

#include "View.h"
#include "SharedView.h"
#include <vector>

class ViewGroup : public SharedView<ViewGroup> {
	protected:
		std::vector<std::shared_ptr<View>> children;
	public:
		ViewGroup();
		void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		void render(const ofRectangle& container);
		selfptr_t addChild(std::shared_ptr<View> view);
		template <typename... Args> selfptr_t addChild(std::shared_ptr<View> head,Args... args){
			addChild(head);
			return addChild(args...);
		}
			
		void onUiDown(ofVec2f& touch);
		void onUiUp(ofVec2f& touch);
};