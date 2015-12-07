#include "TextureView.h"
#include <math.h>

TextureView::TextureView(ofTexture* tex,int _internalFormat,int _numSamples): internalFormat(_internalFormat), numSamples(_numSamples), texture(tex) {}

void TextureView::render(const ofRectangle& container){
	if(
		!fbo.isAllocated() ||
		fbo.getWidth() != container.getWidth() ||
		fbo.getHeight() != container.getHeight()
	){
		fbo.allocate(container.getWidth(),container.getHeight(),internalFormat,numSamples);
	}
	double textureAspectRatio = texture->getWidth() / texture->getHeight();
	double width, height;
	width = container.getWidth();
	height = width / textureAspectRatio;
	if(height < container.getHeight()){
		height = container.getHeight();
		width = height * textureAspectRatio;
	}
	/**
	 * Ensure width/height are even so when we divide by 2, we don't have half
	 * numbers.
	 **/
	width = width + 2.0 - 1.0 - fmod(width - 1.0,2.0);
	height = height + 2.0 - 1.0 - fmod(height - 1.0,2.0);
	fbo.begin();
	ofClear(255,255,255,0);
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	texture->draw(container.getWidth() / 2,container.getHeight() / 2,width,height);
	ofPopStyle();
	fbo.end();
	fbo.draw(container);
}
