#pragma once
#include "SharedView.h"

class TextureView : public SharedView<TextureView> {
	public:
		TextureView(ofTexture* tex,int internalFormat = GL_RGBA,int numSamples = 0);
		ofTexture* texture;
		ofFbo fbo;
		int internalFormat;
		int numSamples;
		void render(const ofRectangle& container);
};
