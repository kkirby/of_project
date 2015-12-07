#pragma once

#include "View.h"

template <typename T> class SharedView : public std::enable_shared_from_this<T>, public View {
	protected:
		typedef T self_t;
		typedef std::shared_ptr<self_t> selfptr_t;
	public:
		selfptr_t getptr(){
			return this->shared_from_this();
		}
		virtual void render(const ofRectangle& container) = 0;
};