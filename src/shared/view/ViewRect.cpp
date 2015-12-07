#include "ViewRect.h"

ViewRect::ViewRect() {}

//--- BEGIN produceViewGroupCode.php
ViewRect& ViewRect::setTopPX(double value){
	top.unit = ViewRect::Size::Unit::PX;
	top.value = value;
	top.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setTopPixel(double value){
	return setTopPX(value);
}

ViewRect& ViewRect::setTop(double value){
	return setTopPX(value);
}

ViewRect& ViewRect::setTopVW(double value){
	top.unit = ViewRect::Size::Unit::VW;
	top.value = value;
	top.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setTopOfViewportWidth(double value){
	return setTopVW(value);
}

ViewRect& ViewRect::setTopVH(double value){
	top.unit = ViewRect::Size::Unit::VH;
	top.value = value;
	top.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setTopOfViewportHeight(double value){
	return setTopVH(value);
}

ViewRect& ViewRect::setTopCW(double value){
	top.unit = ViewRect::Size::Unit::CW;
	top.value = value;
	top.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setTopOfContainerWidth(double value){
	return setTopCW(value);
}

ViewRect& ViewRect::setTopCH(double value){
	top.unit = ViewRect::Size::Unit::CH;
	top.value = value;
	top.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setTopOfContainerHeight(double value){
	return setTopCH(value);
}

ViewRect& ViewRect::setTopPR(double value){
	return setTopOfContainerHeight(value);
}

ViewRect& ViewRect::setTopPercent(double value){
	return setTopPR(value);
}

ViewRect& ViewRect::setRightPX(double value){
	right.unit = ViewRect::Size::Unit::PX;
	right.value = value;
	right.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setRightPixel(double value){
	return setRightPX(value);
}

ViewRect& ViewRect::setRight(double value){
	return setRightPX(value);
}

ViewRect& ViewRect::setRightVW(double value){
	right.unit = ViewRect::Size::Unit::VW;
	right.value = value;
	right.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setRightOfViewportWidth(double value){
	return setRightVW(value);
}

ViewRect& ViewRect::setRightVH(double value){
	right.unit = ViewRect::Size::Unit::VH;
	right.value = value;
	right.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setRightOfViewportHeight(double value){
	return setRightVH(value);
}

ViewRect& ViewRect::setRightCW(double value){
	right.unit = ViewRect::Size::Unit::CW;
	right.value = value;
	right.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setRightOfContainerWidth(double value){
	return setRightCW(value);
}

ViewRect& ViewRect::setRightCH(double value){
	right.unit = ViewRect::Size::Unit::CH;
	right.value = value;
	right.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setRightOfContainerHeight(double value){
	return setRightCH(value);
}

ViewRect& ViewRect::setRightPR(double value){
	return setRightOfContainerWidth(value);
}

ViewRect& ViewRect::setRightPercent(double value){
	return setRightPR(value);
}

ViewRect& ViewRect::setBottomPX(double value){
	bottom.unit = ViewRect::Size::Unit::PX;
	bottom.value = value;
	bottom.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setBottomPixel(double value){
	return setBottomPX(value);
}

ViewRect& ViewRect::setBottom(double value){
	return setBottomPX(value);
}

ViewRect& ViewRect::setBottomVW(double value){
	bottom.unit = ViewRect::Size::Unit::VW;
	bottom.value = value;
	bottom.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setBottomOfViewportWidth(double value){
	return setBottomVW(value);
}

ViewRect& ViewRect::setBottomVH(double value){
	bottom.unit = ViewRect::Size::Unit::VH;
	bottom.value = value;
	bottom.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setBottomOfViewportHeight(double value){
	return setBottomVH(value);
}

ViewRect& ViewRect::setBottomCW(double value){
	bottom.unit = ViewRect::Size::Unit::CW;
	bottom.value = value;
	bottom.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setBottomOfContainerWidth(double value){
	return setBottomCW(value);
}

ViewRect& ViewRect::setBottomCH(double value){
	bottom.unit = ViewRect::Size::Unit::CH;
	bottom.value = value;
	bottom.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setBottomOfContainerHeight(double value){
	return setBottomCH(value);
}

ViewRect& ViewRect::setBottomPR(double value){
	return setBottomOfContainerHeight(value);
}

ViewRect& ViewRect::setBottomPercent(double value){
	return setBottomPR(value);
}

ViewRect& ViewRect::setLeftPX(double value){
	left.unit = ViewRect::Size::Unit::PX;
	left.value = value;
	left.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setLeftPixel(double value){
	return setLeftPX(value);
}

ViewRect& ViewRect::setLeft(double value){
	return setLeftPX(value);
}

ViewRect& ViewRect::setLeftVW(double value){
	left.unit = ViewRect::Size::Unit::VW;
	left.value = value;
	left.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setLeftOfViewportWidth(double value){
	return setLeftVW(value);
}

ViewRect& ViewRect::setLeftVH(double value){
	left.unit = ViewRect::Size::Unit::VH;
	left.value = value;
	left.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setLeftOfViewportHeight(double value){
	return setLeftVH(value);
}

ViewRect& ViewRect::setLeftCW(double value){
	left.unit = ViewRect::Size::Unit::CW;
	left.value = value;
	left.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setLeftOfContainerWidth(double value){
	return setLeftCW(value);
}

ViewRect& ViewRect::setLeftCH(double value){
	left.unit = ViewRect::Size::Unit::CH;
	left.value = value;
	left.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setLeftOfContainerHeight(double value){
	return setLeftCH(value);
}

ViewRect& ViewRect::setLeftPR(double value){
	return setLeftOfContainerWidth(value);
}

ViewRect& ViewRect::setLeftPercent(double value){
	return setLeftPR(value);
}

ViewRect& ViewRect::setWidthPX(double value){
	width.unit = ViewRect::Size::Unit::PX;
	width.value = value;
	width.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setWidthPixel(double value){
	return setWidthPX(value);
}

ViewRect& ViewRect::setWidth(double value){
	return setWidthPX(value);
}

ViewRect& ViewRect::setWidthVW(double value){
	width.unit = ViewRect::Size::Unit::VW;
	width.value = value;
	width.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setWidthOfViewportWidth(double value){
	return setWidthVW(value);
}

ViewRect& ViewRect::setWidthVH(double value){
	width.unit = ViewRect::Size::Unit::VH;
	width.value = value;
	width.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setWidthOfViewportHeight(double value){
	return setWidthVH(value);
}

ViewRect& ViewRect::setWidthCW(double value){
	width.unit = ViewRect::Size::Unit::CW;
	width.value = value;
	width.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setWidthOfContainerWidth(double value){
	return setWidthCW(value);
}

ViewRect& ViewRect::setWidthCH(double value){
	width.unit = ViewRect::Size::Unit::CH;
	width.value = value;
	width.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setWidthOfContainerHeight(double value){
	return setWidthCH(value);
}

ViewRect& ViewRect::setWidthPR(double value){
	return setWidthOfContainerWidth(value);
}

ViewRect& ViewRect::setWidthPercent(double value){
	return setWidthPR(value);
}

ViewRect& ViewRect::setHeightPX(double value){
	height.unit = ViewRect::Size::Unit::PX;
	height.value = value;
	height.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setHeightPixel(double value){
	return setHeightPX(value);
}

ViewRect& ViewRect::setHeight(double value){
	return setHeightPX(value);
}

ViewRect& ViewRect::setHeightVW(double value){
	height.unit = ViewRect::Size::Unit::VW;
	height.value = value;
	height.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setHeightOfViewportWidth(double value){
	return setHeightVW(value);
}

ViewRect& ViewRect::setHeightVH(double value){
	height.unit = ViewRect::Size::Unit::VH;
	height.value = value;
	height.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setHeightOfViewportHeight(double value){
	return setHeightVH(value);
}

ViewRect& ViewRect::setHeightCW(double value){
	height.unit = ViewRect::Size::Unit::CW;
	height.value = value;
	height.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setHeightOfContainerWidth(double value){
	return setHeightCW(value);
}

ViewRect& ViewRect::setHeightCH(double value){
	height.unit = ViewRect::Size::Unit::CH;
	height.value = value;
	height.hasValue = true;
	return *this;
}

ViewRect& ViewRect::setHeightOfContainerHeight(double value){
	return setHeightCH(value);
}

ViewRect& ViewRect::setHeightPR(double value){
	return setHeightOfContainerHeight(value);
}

ViewRect& ViewRect::setHeightPercent(double value){
	return setHeightPR(value);
}

double ViewRect::getTopValue(){
	return top.hasValue ? top.value : 0;
}

ViewRect::Size::Unit ViewRect::getTopUnit(){
	return top.unit;
}

ViewRect& ViewRect::unsetTop(){
	top.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setTop(){
	return unsetTop();
}

double ViewRect::getRightValue(){
	return right.hasValue ? right.value : 0;
}

ViewRect::Size::Unit ViewRect::getRightUnit(){
	return right.unit;
}

ViewRect& ViewRect::unsetRight(){
	right.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setRight(){
	return unsetRight();
}

double ViewRect::getBottomValue(){
	return bottom.hasValue ? bottom.value : 0;
}

ViewRect::Size::Unit ViewRect::getBottomUnit(){
	return bottom.unit;
}

ViewRect& ViewRect::unsetBottom(){
	bottom.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setBottom(){
	return unsetBottom();
}

double ViewRect::getLeftValue(){
	return left.hasValue ? left.value : 0;
}

ViewRect::Size::Unit ViewRect::getLeftUnit(){
	return left.unit;
}

ViewRect& ViewRect::unsetLeft(){
	left.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setLeft(){
	return unsetLeft();
}

double ViewRect::getWidthValue(){
	return width.hasValue ? width.value : 0;
}

ViewRect::Size::Unit ViewRect::getWidthUnit(){
	return width.unit;
}

ViewRect& ViewRect::unsetWidth(){
	width.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setWidth(){
	return unsetWidth();
}

double ViewRect::getHeightValue(){
	return height.hasValue ? height.value : 0;
}

ViewRect::Size::Unit ViewRect::getHeightUnit(){
	return height.unit;
}

ViewRect& ViewRect::unsetHeight(){
	height.hasValue = false;
	return *this;
}

ViewRect& ViewRect::setHeight(){
	return unsetHeight();
}
//--- END produceViewGroupCode.php

double getMultiplierForUnit(const ViewRect::Size::Unit& unit,const ofRectangle& container,const ofRectangle& viewport){
	if(unit == ViewRect::Size::Unit::PX)return 1;
	const ofRectangle& basisRect = *(const ofRectangle*[]){&container,&viewport}[(int)ViewRect::Size::UnitToUnitBasis[unit]];
	return (double[]){basisRect.getWidth(),basisRect.getHeight()}[(int)ViewRect::Size::UnitToUnitAxis[unit]];
	
}

double formatValue(ViewRect::Size size,const ofRectangle& container,const ofRectangle& viewport){
	if(size.hasValue){
		if(size.unit != ViewRect::Size::Unit::PX){
			return (size.value/100.0) * getMultiplierForUnit(size.unit,container,viewport);
		}
		else {
			return size.value;
		}
	}
	else {
		return 0;
	}
}

ofRectangle ViewRect::getOfRect(const ofRectangle& container,const ofRectangle& viewport){
	double
		topV = formatValue(top,container,viewport),
		rightV = formatValue(right,container,viewport),
		bottomV = formatValue(bottom,container,viewport),
		leftV = formatValue(left,container,viewport),
		widthV = formatValue(width,container,viewport),
		heightV = formatValue(height,container,viewport);
	double topR, rightR, bottomR, leftR, widthR, heightR;

	// X
	if(top.hasValue){
		topR = topV;
		if(bottom.hasValue){
			heightR = container.getHeight() - bottomV;
		}
		else if(height.hasValue){
			heightR = heightV;
		}
	}
	else if(bottom.hasValue){
		topR = container.getHeight() - bottomV;
		if(height.hasValue){
			topR -= heightV;
			heightR = heightV;
		}
	}
	else {
		topR = 0;
		if(height.hasValue){
			heightR = heightV;
		}
	}
	if(!height.hasValue && !bottom.hasValue){
		heightR = container.getHeight() - topR;
	}

	// Y
	if(left.hasValue){
		leftR = leftV;
		if(right.hasValue){
			widthR = container.getWidth() - rightV;
		}
		else if(width.hasValue){
			widthR = widthV;
		}
		else {
			widthR = container.getWidth() - leftR;
		}
	}
	else if(right.hasValue){
		leftR = container.getWidth() - rightV;
		if(width.hasValue){
			leftR -= widthV;
			widthR = widthV;
		}
		else {
			widthR = container.getWidth() - leftR;
		}
	}
	else {
		leftR = 0;
		if(width.hasValue){
			widthR = widthV;
		}
	}
	if(!width.hasValue && !right.hasValue){
		widthR = container.getWidth() - leftR;
	}

	topR += container.getY();
	leftR += container.getX();
	return ofRectangle(leftR,topR,widthR,heightR);
}

std::string ViewRect::Size::toString(){
	if(hasValue){
		return ofVAArgsToString(
			"SizeValue[Value(%f), Unit(%s)]",
			value,
			unitDescriptions[unit]
		);
	}
	else {
		return ofVAArgsToString(
			"SizeValue[Value(%s), Unit(%s)]",
			"null",
			"null"
		);
	}
}

std::string ViewRect::toString(){
	return ofVAArgsToString(
		"ViewRect[Top(%s), Right(%s), Bottom(%s), Left(%s), Width(%s), Height(%s)]",
		top.toString().c_str(),
		right.toString().c_str(),
		bottom.toString().c_str(),
		left.toString().c_str(),
		width.toString().c_str(),
		height.toString().c_str()
	);
}

std::map<ViewRect::Size::Unit,const char*> ViewRect::Size::unitDescriptions = {
	{ViewRect::Size::Unit::PX,"px"},
	{ViewRect::Size::Unit::CW,"cw"},
	{ViewRect::Size::Unit::CH,"ch"},
	{ViewRect::Size::Unit::VW,"vw"},
	{ViewRect::Size::Unit::VH,"vh"}
};

std::map<std::string,ViewRect::Size::Unit> ViewRect::Size::UnitStringToUnit = {
	{"px",ViewRect::Size::Unit::PX},
	{"cw",ViewRect::Size::Unit::CW},
	{"ch",ViewRect::Size::Unit::CH},
	{"vw",ViewRect::Size::Unit::VW},
	{"vh",ViewRect::Size::Unit::VH}
};

std::map<ViewRect::Size::Unit,ViewRect::Size::UnitAxis> ViewRect::Size::UnitToUnitAxis = {
	{ViewRect::Size::Unit::PX,ViewRect::Size::UnitAxis::NONE},
	{ViewRect::Size::Unit::CW,ViewRect::Size::UnitAxis::X},
	{ViewRect::Size::Unit::CH,ViewRect::Size::UnitAxis::Y},
	{ViewRect::Size::Unit::VW,ViewRect::Size::UnitAxis::X},
	{ViewRect::Size::Unit::VH,ViewRect::Size::UnitAxis::Y}
};

std::map<std::string,ViewRect::Size::UnitAxis> ViewRect::Size::PropertyToUnitAxis = {
	{"width",ViewRect::Size::UnitAxis::X},
	{"left",ViewRect::Size::UnitAxis::X},
	{"right",ViewRect::Size::UnitAxis::X},
	{"height",ViewRect::Size::UnitAxis::Y},
	{"top",ViewRect::Size::UnitAxis::Y},
	{"bottom",ViewRect::Size::UnitAxis::Y}
};

std::map<ViewRect::Size::UnitAxis,std::map<ViewRect::Size::UnitBasis,ViewRect::Size::Unit>> ViewRect::Size::UnitAxisToUnit = {
	{ViewRect::Size::UnitAxis::X,{
		{ViewRect::Size::UnitBasis::CONTAINER,ViewRect::Size::Unit::CW},
		{ViewRect::Size::UnitBasis::VIEWPORT,ViewRect::Size::Unit::VW}
	}},
	{ViewRect::Size::UnitAxis::Y,{
		{ViewRect::Size::UnitBasis::CONTAINER,ViewRect::Size::Unit::CH},
		{ViewRect::Size::UnitBasis::VIEWPORT,ViewRect::Size::Unit::VH}
	}}
};

std::map<ViewRect::Size::Unit,ViewRect::Size::UnitBasis> ViewRect::Size::UnitToUnitBasis = {
	{ViewRect::Size::Unit::PX,ViewRect::Size::UnitBasis::NONE},
	{ViewRect::Size::Unit::CW,ViewRect::Size::UnitBasis::CONTAINER},
	{ViewRect::Size::Unit::CH,ViewRect::Size::UnitBasis::CONTAINER},
	{ViewRect::Size::Unit::VW,ViewRect::Size::UnitBasis::VIEWPORT},
	{ViewRect::Size::Unit::VH,ViewRect::Size::UnitBasis::VIEWPORT}
};