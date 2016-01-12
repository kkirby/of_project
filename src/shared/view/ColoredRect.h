#pragma once

#include "View.h"

class ColoredRect : public View {
	public:
		int r;
		int g;
		int b;
		ColoredRect(int r,int g,int b);
		void renderContent() const;
		
		virtual void onUiUp(const ofVec2f& touch);
		virtual void onUiDown(const ofVec2f& touch);
		virtual void onUiClicked(const ofVec2f& touch);
};

