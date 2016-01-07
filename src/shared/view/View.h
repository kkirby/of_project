#pragma once

#include "ofMain.h"
#include "ViewRect.h"
#include "../macros.h"
#include "ViewInteraction.h"
#include <memory>

#define VIEW2(name,parent) class name : public parent
#define VIEW1(name) VIEW2(name,View)
#define VIEW(...) VFUNC(VIEW, __VA_ARGS__)

class View : public std::enable_shared_from_this<View> {
	public:
		ViewRect rect;
		const char* id;
		View();
		
		ViewInteraction interaction;
		
		ofRectangle worldRect;
		
		virtual void recalculateWorld(const ofRectangle& container,const ofRectangle& viewport);
		
		virtual void update(){}
		
		virtual void render() const;
		virtual void renderChildren() const;
		virtual void renderContent() const {};
		
		virtual void uiDown(const ofVec2f& pt);
		virtual void uiUp(const ofVec2f& pt);
		virtual void uiMove(const ofVec2f& pt);
		
		virtual std::shared_ptr<View> getptr();
		
		virtual std::shared_ptr<View> addChild(std::shared_ptr<View> view);
			
	protected:
		std::vector<std::shared_ptr<View>> children;
		virtual void onUiDown(const ofVec2f& pt){};
		virtual void onUiUp(const ofVec2f& pt){};
		virtual void onUiMove(const ofVec2f& pt){};
		virtual void onUiClicked(const ofVec2f& pt){};
};