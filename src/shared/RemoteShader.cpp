#include "RemoteShader.h"

RemoteShader::RemoteShader(std::string iVertexShader,std::string iFragmentShader): vertexShader(iVertexShader), fragmentShader(iFragmentShader) {
	
}

void RemoteShader::refresh(){
	ofHttpResponse vertexShaderSource = ofLoadURL(vertexShader);
	ofHttpResponse fragmentShaderSource = ofLoadURL(fragmentShader);
	setupShaderFromSource(
		GL_VERTEX_SHADER,
		vertexShaderSource.data.getText()
	);
	setupShaderFromSource(
		GL_FRAGMENT_SHADER,
		fragmentShaderSource.data.getText()
	);
	bindDefaults();
	linkProgram();
};