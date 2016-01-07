#pragma once

#include "AbstractFilter.h"
#include <vector>

class GroupFilter : public AbstractFilter {
	public:
		ofFbo ping;
		ofFbo pong;
		vector<AbstractFilter*> filters;
		void push_back(AbstractFilter* filter);
		void begin();
		void end();
		virtual ~GroupFilter() = default;
};