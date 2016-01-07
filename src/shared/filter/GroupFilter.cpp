#include "GroupFilter.h"

void GroupFilter::push_back(AbstractFilter* filter){
	filters.push_back(filter);
}

void GroupFilter::begin(){
	if(
		!ping.isAllocated() ||
		ping.getWidth() != ofGetWidth() ||
		ping.getHeight() != ofGetHeight()
	){
		ping.allocate(ofGetWidth(),ofGetHeight());
		ping.allocate(ofGetWidth(),ofGetHeight());
	}
	if(
		!pong.isAllocated() ||
		pong.getWidth() != ofGetWidth() ||
		pong.getHeight() != ofGetHeight()
	){
		pong.allocate(ofGetWidth(),ofGetHeight());
	}
	ping.begin();
	ofClear(0,0,0,0);
	if(filters.size() > 0)filters[0]->begin();
}

void GroupFilter::end(){
	if(filters.size() > 0)filters[0]->end();
	ping.end();
	int filterIndex = 1;
	while(filterIndex < filters.size()){
		bool isPong = (filterIndex % 2) == 1;
		
		if(isPong)pong.begin();
		else ping.begin();
		
		ofClear(0,0,0,0);
		
		filters[filterIndex]->begin();
		
		if(isPong)ping.draw(0,0);
		else pong.draw(0,0);
		
		filters[filterIndex]->end();
		
		if(isPong)pong.end();
		else ping.end();
		filterIndex++;
	};
	if(filterIndex % 2 == 1)ping.draw(0,0);
	else pong.draw(0,0);
}