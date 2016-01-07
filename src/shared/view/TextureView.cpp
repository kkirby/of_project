#include "TextureView.h"
#include <math.h>

TextureView::TextureView(ofTexture* tex,int _internalFormat,int _numSamples): internalFormat(_internalFormat), numSamples(_numSamples), texture(tex) {}

void TextureView::update(){
	if(
		!fbo.isAllocated() ||
		fbo.getWidth() != (int)worldRect.getWidth() ||
		fbo.getHeight() != (int)worldRect.getHeight()
	){
		fbo.allocate(worldRect.getWidth(),worldRect.getHeight(),internalFormat,numSamples);
	}
}

void TextureView::render() const {
	fbo.begin();
	ofClear(0,0,0,0);
	ofRectangle target(0,0,fbo.getWidth(),fbo.getHeight());
	ofRectangle source(0,0,texture->getWidth(),texture->getHeight());
	source.scaleTo(target,OF_SCALEMODE_FILL);
	texture->draw(source);
	fbo.end();
	fbo.draw(worldRect);
}
