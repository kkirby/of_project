#pragma once

#include "AbstractShaderFilter.h"
#include "GroupFilter.h"

class GaussianBlurFilter : public GroupFilter {
	public:
		GaussianBlurFilter();
		virtual ~GaussianBlurFilter();
	protected:
		AbstractShaderFilter* filterA;
		AbstractShaderFilter* filterB;
};