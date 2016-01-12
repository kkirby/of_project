#pragma once
#include "View.h"
#include <vector>

class TextureView : public View {
	public:
		TextureView(ofBaseDraws* tex,int internalFormat = GL_RGBA,int numSamples = 0);
		ofBaseDraws* texture;
		ofFbo fbo;
		int internalFormat;
		int numSamples;
		virtual void renderContent() const;
		virtual void rectUpdated();
};
