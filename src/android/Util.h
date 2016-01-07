#include <ofMain.h>
#ifdef TARGET_ANDROID
namespace androidUtil {
	int getDeviceRotation();
}
#endif