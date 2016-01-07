#pragma once

#include <map>
#include <string>
#include <iostream>
#include <regex>
#include <math.h>
#include "View.h"

namespace ViewBuilderNS {
	
	bool parseString(const char* key,const char* str,ViewRect::Size& info);
	
	template <typename A,typename B> bool mapHasKey(const std::map<A,B>& map,A key){
		return map.count(key) == 1;
	}

	template <typename A,typename B> bool parseSizeStringIfHas(std::map<A,B> props,const char* key,ViewRect::Size& info){
		if(mapHasKey(props,key)){
			return parseString(key,props[key],info);
		}
		else {
			return false;
		}
	}
}

/*template <typename T,typename... Args> std::shared_ptr<T> ViewBuilder(std::map<const char*,const char*> props,Args... args){
	return ViewBuilderNS::ViewBuilder<T,Args...>(props,args...);
}*/
template <typename T,typename... Args> std::shared_ptr<T> ViewBuilder(std::map<const char*,const char*> props,Args... args){
	static_assert(
		std::is_base_of<View, T>::value, 
		"T must be a descendant of View"
	);
	auto instance = std::shared_ptr<T>(new T(args...));
	
	bool fill = ViewBuilderNS::mapHasKey(props,"fill");
	if(ViewBuilderNS::mapHasKey(props,"fillX") || fill){
		instance->rect.setLeftPX(0);
		instance->rect.setRightPX(0);
	}
	if(ViewBuilderNS::mapHasKey(props,"fillY") || fill){
		instance->rect.setTopPX(0);
		instance->rect.setBottomPX(0);
	}
	
	ViewBuilderNS::parseSizeStringIfHas(props,"width",instance->rect.width);
	ViewBuilderNS::parseSizeStringIfHas(props,"height",instance->rect.height);
	ViewBuilderNS::parseSizeStringIfHas(props,"top",instance->rect.top);
	ViewBuilderNS::parseSizeStringIfHas(props,"right",instance->rect.right);
	ViewBuilderNS::parseSizeStringIfHas(props,"bottom",instance->rect.bottom);
	ViewBuilderNS::parseSizeStringIfHas(props,"left",instance->rect.left);
	if(ViewBuilderNS::mapHasKey(props,"id")){
		instance->id = props["id"];
	}
	return instance;
}