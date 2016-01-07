#include "AbstractShaderFilter.h"

class BrightnessFilter : public AbstractShaderFilter {
	public:
		BrightnessFilter(float brightness);
		void setBrightness(float brightness);
		std::string getFragmentSource();
};