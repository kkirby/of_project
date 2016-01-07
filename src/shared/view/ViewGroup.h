#pragma once

#include "View.h"
#include <vector>

VIEW(ViewGroup){
	protected:
		std::vector<std::shared_ptr<View>> children;
	public:
		ViewGroup();
		void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		virtual void render() const;
		selfptr_t addChild(std::shared_ptr<View> view);
		template <typename... Args> selfptr_t addChild(std::shared_ptr<View> head,Args... args){
			addChild(head);
			return addChild(args...);
		}
		
		void uiDown(const ofVec2f& touch);
		void uiMove(const ofVec2f& touch);
		void uiUp(const ofVec2f& touch);
};