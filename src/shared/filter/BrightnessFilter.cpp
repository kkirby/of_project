#include "BrightnessFilter.h"

BrightnessFilter::BrightnessFilter(float brightness){
	_addParameter(new ParameterF("brightness", brightness));
}

void BrightnessFilter::setBrightness(float brightness){
	updateParameter("brightness", brightness);
}

std::string BrightnessFilter::getFragmentSource(){
	return GLSL_FRAG_STRING(
		uniform float brightness;
		
		void main(){
			vec4 color = texture2D(inputImageTexture,vtexcoord);
			gl_FragColor = vec4((color.rgb + vec3(brightness)),color.a);
		}
	);
}