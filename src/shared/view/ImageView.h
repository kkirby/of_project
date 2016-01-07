#pragma once

#include "View.h"
#include <string>

VIEW(ImageView){
	public:
		ImageView(ofImage image);
		ImageView(const char* imageSrc);
		ofImage image;
		virtual void renderContent() const;
};