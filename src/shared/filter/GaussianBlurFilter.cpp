#include "GaussianBlurFilter.h"
#include "AbstractShaderFilter.h"

class GaussianBlurFilterHV : public AbstractShaderFilter {
	protected:
		std::string getFragmentSource(){
			return GLSL_FRAG_STRING(
				varying vec2 blurTextureCoordinates[14];
				void main(){
					gl_FragColor = vec4(0.0);
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[0])*0.0044299121055113265;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[1])*0.00895781211794;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[2])*0.0215963866053;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[3])*0.0443683338718;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[4])*0.0776744219933;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[5])*0.115876621105;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[6])*0.147308056121;
					gl_FragColor += texture2D(inputImageTexture,vtexcoord)*0.159576912161;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[7])*0.147308056121;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[8])*0.115876621105;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[9])*0.0776744219933;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[10])*0.0443683338718;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[11])*0.0215963866053;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[12])*0.00895781211794;
					gl_FragColor += texture2D(inputImageTexture,blurTextureCoordinates[13])*0.0044299121055113265;
				}
			);
		}
};

class GaussianBlurFilterH : public GaussianBlurFilterHV {
	protected:
		std::string getVertexSource(){
			return GLSL_VERT_STRING(
				varying vec2 blurTextureCoordinates[14];
				
				void main(){
					gl_Position = modelViewProjectionMatrix * position;
					vtexcoord = texcoord;
					blurTextureCoordinates[0] = vtexcoord + vec2(-0.028,0.0);
					blurTextureCoordinates[1] = vtexcoord + vec2(-0.024,0.0);
					blurTextureCoordinates[2] = vtexcoord + vec2(-0.020,0.0);
					blurTextureCoordinates[3] = vtexcoord + vec2(-0.016,0.0);
					blurTextureCoordinates[4] = vtexcoord + vec2(-0.012,0.0);
					blurTextureCoordinates[5] = vtexcoord + vec2(-0.008,0.0);
					blurTextureCoordinates[6] = vtexcoord + vec2(-0.004,0.0);
					blurTextureCoordinates[7] = vtexcoord + vec2(0.004,0.0);
					blurTextureCoordinates[8] = vtexcoord + vec2(0.008,0.0);
					blurTextureCoordinates[9] = vtexcoord + vec2(0.012,0.0);
					blurTextureCoordinates[10] = vtexcoord + vec2(0.016,0.0);
					blurTextureCoordinates[11] = vtexcoord + vec2(0.020,0.0);
					blurTextureCoordinates[12] = vtexcoord + vec2(0.024,0.0);
					blurTextureCoordinates[13] = vtexcoord + vec2(0.028,0.0);
				}
			);
		}
};

class GaussianBlurFilterV : public GaussianBlurFilterHV {
	protected:
		virtual std::string getVertexSource(){
			return GLSL_VERT_STRING(
				varying vec2 blurTextureCoordinates[14];
				
				void main(){
					gl_Position = modelViewProjectionMatrix * position;
					vtexcoord = texcoord;
					blurTextureCoordinates[0] = vtexcoord + vec2(0.0,-0.028);
					blurTextureCoordinates[1] = vtexcoord + vec2(0.0,-0.024);
					blurTextureCoordinates[2] = vtexcoord + vec2(0.0,-0.020);
					blurTextureCoordinates[3] = vtexcoord + vec2(0.0,-0.016);
					blurTextureCoordinates[4] = vtexcoord + vec2(0.0,-0.012);
					blurTextureCoordinates[5] = vtexcoord + vec2(0.0,-0.008);
					blurTextureCoordinates[6] = vtexcoord + vec2(0.0,-0.004);
					blurTextureCoordinates[7] = vtexcoord + vec2(0.0,0.004);
					blurTextureCoordinates[8] = vtexcoord + vec2(0.0,0.008);
					blurTextureCoordinates[9] = vtexcoord + vec2(0.0,0.012);
					blurTextureCoordinates[10] = vtexcoord + vec2(0.0,0.016);
					blurTextureCoordinates[11] = vtexcoord + vec2(0.0,0.020);
					blurTextureCoordinates[12] = vtexcoord + vec2(0.0,0.024);
					blurTextureCoordinates[13] = vtexcoord + vec2(0.0,0.028);
				}
			);
		}
};

GaussianBlurFilter::GaussianBlurFilter(){
	filterA = new GaussianBlurFilterH();
	filterB = new GaussianBlurFilterV();
	push_back(filterA);
	push_back(filterB);
}

GaussianBlurFilter::~GaussianBlurFilter(){
	delete filterA;
	delete filterB;
}