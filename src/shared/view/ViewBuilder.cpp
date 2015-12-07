#include "ViewBuilder.h"

bool ViewBuilderNS::parseString(const char* key,const char* str,ViewRect::Size& info){
	std::cmatch matches;
	if(std::regex_match(str,matches,std::regex("^(\\d+(?:\\.\\d+)?)(px|[cv][hw]|%)$"))){
		std::string unitStr = matches[2].str();
		if(!mapHasKey(ViewRect::Size::UnitStringToUnit,unitStr)){
			if(unitStr == "%"){
				info.unit = ViewRect::Size::UnitAxisToUnit[ViewRect::Size::PropertyToUnitAxis[key]][ViewRect::Size::UnitBasis::CONTAINER];
			}
			else {
				throw "no valid unit found.";
			}
		}
		else {
			info.unit = ViewRect::Size::UnitStringToUnit[unitStr];
		}
		info.value = ofToDouble(matches[1].str());
		info.hasValue = true;
		return true;
	}
	return false;
}