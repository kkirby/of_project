#pragma once

#include "ofMain.h"

class ViewRect {
	public:

		struct Size {
			enum class Unit {PX,CW,CH,VW,VH};
			static std::map<Unit,const char*> unitDescriptions;
			static std::map<std::string,Unit> UnitStringToUnit;
			
			enum class UnitBasis: int {CONTAINER=0,VIEWPORT=1,NONE=3};
			static std::map<Unit,UnitBasis> UnitToUnitBasis;
			
			enum class UnitAxis: int {X=0,Y=1,NONE=3};
			static std::map<Unit,UnitAxis> UnitToUnitAxis;
			static std::map<std::string,UnitAxis> PropertyToUnitAxis;
			static std::map<UnitAxis,std::map<UnitBasis,Unit>> UnitAxisToUnit;
			
			Size() : value(0), hasValue(false), unit(Unit::PX) {}
			double value;
			Unit unit;
			bool hasValue;
			bool isCenter;
			
			std::string toString();
		};

	public:
	
		Size top;
		Size right;
		Size bottom;
		Size left;
		Size width;
		Size height;

		ViewRect();

		ofRectangle getOfRect(const ofRectangle& container,const ofRectangle& viewport);
		std::string toString();

		//--- BEGIN produceViewGroupCode.php
		ViewRect& setTopPX(double value);
		ViewRect& setTopPixel(double value);
		ViewRect& setTop(double value);
		ViewRect& setTopVW(double value);
		ViewRect& setTopOfViewportWidth(double value);
		ViewRect& setTopVH(double value);
		ViewRect& setTopOfViewportHeight(double value);
		ViewRect& setTopCW(double value);
		ViewRect& setTopOfContainerWidth(double value);
		ViewRect& setTopCH(double value);
		ViewRect& setTopOfContainerHeight(double value);
		ViewRect& setTopPR(double value);
		ViewRect& setTopPercent(double value);
		ViewRect& setRightPX(double value);
		ViewRect& setRightPixel(double value);
		ViewRect& setRight(double value);
		ViewRect& setRightVW(double value);
		ViewRect& setRightOfViewportWidth(double value);
		ViewRect& setRightVH(double value);
		ViewRect& setRightOfViewportHeight(double value);
		ViewRect& setRightCW(double value);
		ViewRect& setRightOfContainerWidth(double value);
		ViewRect& setRightCH(double value);
		ViewRect& setRightOfContainerHeight(double value);
		ViewRect& setRightPR(double value);
		ViewRect& setRightPercent(double value);
		ViewRect& setBottomPX(double value);
		ViewRect& setBottomPixel(double value);
		ViewRect& setBottom(double value);
		ViewRect& setBottomVW(double value);
		ViewRect& setBottomOfViewportWidth(double value);
		ViewRect& setBottomVH(double value);
		ViewRect& setBottomOfViewportHeight(double value);
		ViewRect& setBottomCW(double value);
		ViewRect& setBottomOfContainerWidth(double value);
		ViewRect& setBottomCH(double value);
		ViewRect& setBottomOfContainerHeight(double value);
		ViewRect& setBottomPR(double value);
		ViewRect& setBottomPercent(double value);
		ViewRect& setLeftPX(double value);
		ViewRect& setLeftPixel(double value);
		ViewRect& setLeft(double value);
		ViewRect& setLeftVW(double value);
		ViewRect& setLeftOfViewportWidth(double value);
		ViewRect& setLeftVH(double value);
		ViewRect& setLeftOfViewportHeight(double value);
		ViewRect& setLeftCW(double value);
		ViewRect& setLeftOfContainerWidth(double value);
		ViewRect& setLeftCH(double value);
		ViewRect& setLeftOfContainerHeight(double value);
		ViewRect& setLeftPR(double value);
		ViewRect& setLeftPercent(double value);
		ViewRect& setWidthPX(double value);
		ViewRect& setWidthPixel(double value);
		ViewRect& setWidth(double value);
		ViewRect& setWidthVW(double value);
		ViewRect& setWidthOfViewportWidth(double value);
		ViewRect& setWidthVH(double value);
		ViewRect& setWidthOfViewportHeight(double value);
		ViewRect& setWidthCW(double value);
		ViewRect& setWidthOfContainerWidth(double value);
		ViewRect& setWidthCH(double value);
		ViewRect& setWidthOfContainerHeight(double value);
		ViewRect& setWidthPR(double value);
		ViewRect& setWidthPercent(double value);
		ViewRect& setHeightPX(double value);
		ViewRect& setHeightPixel(double value);
		ViewRect& setHeight(double value);
		ViewRect& setHeightVW(double value);
		ViewRect& setHeightOfViewportWidth(double value);
		ViewRect& setHeightVH(double value);
		ViewRect& setHeightOfViewportHeight(double value);
		ViewRect& setHeightCW(double value);
		ViewRect& setHeightOfContainerWidth(double value);
		ViewRect& setHeightCH(double value);
		ViewRect& setHeightOfContainerHeight(double value);
		ViewRect& setHeightPR(double value);
		ViewRect& setHeightPercent(double value);
		
		double getTopValue();
		ViewRect::Size::Unit getTopUnit();
		ViewRect& unsetTop();
		ViewRect& setTop();
		double getRightValue();
		ViewRect::Size::Unit getRightUnit();
		ViewRect& unsetRight();
		ViewRect& setRight();
		double getBottomValue();
		ViewRect::Size::Unit getBottomUnit();
		ViewRect& unsetBottom();
		ViewRect& setBottom();
		double getLeftValue();
		ViewRect::Size::Unit getLeftUnit();
		ViewRect& unsetLeft();
		ViewRect& setLeft();
		double getWidthValue();
		ViewRect::Size::Unit getWidthUnit();
		ViewRect& unsetWidth();
		ViewRect& setWidth();
		double getHeightValue();
		ViewRect::Size::Unit getHeightUnit();
		ViewRect& unsetHeight();
		ViewRect& setHeight();
		//--- END produceViewGroupCode.php
};
