#include "size.h"

util::size::size(const ofRectangle& rect): width(rect.width), height(rect.height){}
util::size::size(float width,float height): width(width), height(height){}

bool operator < (const util::size& lhs,const util::size& rhs){
	return lhs.width < rhs.width || lhs.height < rhs.height;
}

bool operator > (const util::size& lhs,const util::size& rhs){
	return rhs < lhs;
}
bool operator <= (const util::size& lhs,const util::size& rhs){
	return !(lhs > rhs);
}
bool operator >= (const util::size& lhs,const util::size& rhs){
	return !(lhs < rhs);
}