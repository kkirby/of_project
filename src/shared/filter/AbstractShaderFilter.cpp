#include "AbstractShaderFilter.h"

std::string AbstractShaderFilter::getVertexSource(){
	return GLSL_VERT_STRING(
		void main(){
			gl_Position = modelViewProjectionMatrix * position;
			vtexcoord = texcoord;
		}
	);
}
std::string AbstractShaderFilter::getFragmentSource(){
	return GLSL_FRAG_STRING(
		void main(){
			gl_FragColor = texture2D(inputImageTexture,vtexcoord);
		}
	);
}

void AbstractShaderFilter::setupShader(){
	shader.setupShaderFromSource(GL_VERTEX_SHADER,getVertexSource());
	shader.setupShaderFromSource(GL_FRAGMENT_SHADER,getFragmentSource());
	shader.bindDefaults();
	shader.linkProgram();
}

void AbstractShaderFilter::begin(){
	if(!shader.isLoaded()){
		setupShader();
	}
	shader.begin();
	_updateParameters(&shader);
}

void AbstractShaderFilter::end(){
	shader.end();
}