#pragma once

#include "SharedView.h"

class ColoredRect : public SharedView<ColoredRect> {
	public:
		int r;
		int g;
		int b;
		ColoredRect(int r,int g,int b);
		void render(const ofRectangle& container);
		
		void onUiUp(ofVec2f& touch);
};

