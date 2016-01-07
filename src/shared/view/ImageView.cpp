#include "ImageView.h"

ImageView::ImageView(ofImage image): image(image) {
	
}

ImageView::ImageView(const char* imageSrc) {
	image.load(imageSrc);
}

void ImageView::render() const {
	image.draw(worldRect);
}
