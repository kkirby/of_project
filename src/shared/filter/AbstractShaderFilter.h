#pragma once

#include "AbstractFilter.h"
#include "parameters/ParametricObject.h"
#include <ofMain.h>
#include <string>

#ifdef TARGET_OPENGLES
#define GLSL_VERT_STRING(shader) \
"attribute vec4 position;\n" \
"attribute vec4 color;\n" \
"attribute vec4 normal;\n" \
"attribute vec2 texcoord;\n" \
"uniform mat4 modelViewMatrix;\n" \
"uniform mat4 projectionMatrix;\n" \
"uniform mat4 modelViewProjectionMatrix;\n" \
"varying vec2 vtexcoord;\n" \
#shader

#define GLSL_FRAG_STRING(shader) \
"precision mediump float;\n" \
"varying highp vec2 vtexcoord;\n" \
"uniform sampler2D inputImageTexture;\n" \
#shader
#else
#define GLSL_VERT_STRING(shader) \
"#version 120\n" \
"attribute vec4 position;\n" \
"attribute vec4 color;\n" \
"attribute vec4 normal;\n" \
"attribute vec2 texcoord;\n" \
"uniform mat4 modelViewMatrix;\n" \
"uniform mat4 projectionMatrix;\n" \
"uniform mat4 modelViewProjectionMatrix;\n" \
"varying vec2 vtexcoord;\n" \
#shader

#define GLSL_FRAG_STRING(shader) \
"#version 120\n" \
"varying vec2 vtexcoord;\n" \
"uniform sampler2D inputImageTexture;\n" \
#shader
#endif

class AbstractShaderFilter : public AbstractFilter, public ParametricObject {
	public:
		virtual void begin();
		virtual void end();
		virtual ~AbstractShaderFilter() = default;
		ofShader shader;
		virtual std::string getFragmentSource();
		virtual std::string getVertexSource();
		void setupShader();
		
};