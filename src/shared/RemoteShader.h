#include <ofMain.h>
#include <string>

class RemoteShader : public ofShader {
	public:
		std::string fragmentShader;
		std::string vertexShader;
		RemoteShader(std::string iVertexShader,std::string iFragmentShader);
		void refresh();
};