#pragma once

#include <memory>

template <typename T> class SharedView : public std::enable_shared_from_this<T> {
	public:
		typedef T self_t;
		typedef std::shared_ptr<self_t> selfptr_t;
		virtual selfptr_t getptr(){
			return this->shared_from_this();
		}
};