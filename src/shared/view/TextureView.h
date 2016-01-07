#pragma once
#include "View.h"
#include <vector>

VIEW(TextureView){
	public:
		TextureView(ofTexture* tex,int internalFormat = GL_RGBA,int numSamples = 0);
		ofTexture* texture;
		ofFbo fbo;
		int internalFormat;
		int numSamples;
		virtual void render() const;
		virtual void update();
};
