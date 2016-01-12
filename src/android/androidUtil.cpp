#include "androidUtil.h"
#ifdef TARGET_ANDROID
#include <jni.h>
#include "android/javaClass.h"

int androidUtil::getDeviceRotation(){
	jclass javaClass = ofGetJNIEnv()->FindClass("com/someplace/asdf/Util");
	if(!javaClass){
		ofLogError("getDeviceRotation") << "unable to find com.someplace.asdf.Util class.";
		return 0;
	}
	jmethodID method = ofGetJNIEnv()->GetStaticMethodID(javaClass,"GetScreenRotation","()I");
	if(!method){
		ofLogError("JavaObject::getJavaClass") << "unable to find method GetScreenRotation class.";
		return 0;
	}
	jint res = ofGetJNIEnv()->CallStaticIntMethod(javaClass,method);
	return res;
}
#endif