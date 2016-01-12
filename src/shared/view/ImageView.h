#pragma once

#include "View.h"
#include <string>

class ImageView : public View {
	public:
		ImageView(ofImage image,ofScaleMode scaleMode = OF_SCALEMODE_FIT);
		ImageView(const char* imageSrc);
		ofImage image;
		ofScaleMode scaleMode;
		ofRectangle imageRect;
		virtual void renderContent() const;
		virtual void rectUpdated();
};