#pragma once

#include "ofMain.h"

namespace util {

	class size {
		public:
			size(const ofRectangle& rect);
			size(float width,float height);
			float width;
			float height;
	};

}

bool operator < (const util::size& lhs,const util::size& rhs);
bool operator > (const util::size& lhs, const util::size& rhs);
bool operator <= (const util::size& lhs, const util::size& rhs);
bool operator >= (const util::size& lhs, const util::size& rhs);