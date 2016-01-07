#pragma once

#include "parameters/ParametricObject.h"
#include <ofMain.h>
#include <string>

class AbstractFilter {
	public:
		virtual void begin() = 0;
		virtual void end() = 0;
		virtual ~AbstractFilter() = default;
		
};