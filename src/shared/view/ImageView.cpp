#include "ImageView.h"

ImageView::ImageView(ofImage image,ofScaleMode scaleMode): image(image), scaleMode(scaleMode) {
	
}

ImageView::ImageView(const char* imageSrc) {
	image.load(imageSrc);
}

void ImageView::renderContent() const {
	image.draw(imageRect);
}

void ImageView::rectUpdated() {
	imageRect.set(worldRect.x,worldRect.y,image.getWidth(),image.getHeight());
	imageRect.scaleTo(worldRect,scaleMode);
}