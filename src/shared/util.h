#pragma once

#include <sstream>
#include <string>

namespace util {
	template <typename T> std::string describe(T item){
		std::stringbuf buffer;
	}
	
	template <typename T> void describe(T item,const std::stringbuf& buffer);
	
}