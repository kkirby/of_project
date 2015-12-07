#include "cameraPlugin.h"

#if defined (TARGET_ANDROID)

CameraPlugin::CameraPlugin() : JavaClass("com/someplace/asdf/CameraPlugin") {}

void CameraPlugin::setGrabber(ofxAndroidVideoGrabber* grabber){
	jobject camera = JavaClass::getObjectField(grabber->data->javaVideoGrabber,"camera","Landroid/hardware/Camera;");
	if(!camera){
		ofLogError("CameraPlugin") << " couldn't find camera on videoGrabber";
		return;
	}
	callVoidMethod("setCamera","Landroid/hardware/Camera;",camera);
}

void CameraPlugin::takePhoto(){
	callVoidMethod("takePhoto","");
}

extern "C" {
	void Java_com_someplace_asdf_CameraPlugin_onPhotoCb(JNIEnv* env,jobject thiz,jbyteArray data){
		/**
		 * I'm currently unsure if we need to copy the data from `data` or if we can use
		 * a pointer to it. My conflict is that I'm not sure if ofImage requires the
		 * data after it has been loaded.
		 **/
		ofBuffer buffer;
		size_t length = ofGetJNIEnv()->GetArrayLength(data);
		buffer.allocate(length);
		env->GetByteArrayRegion(data,0,length,(jbyte*)buffer.getBinaryBuffer());
		JavaClass::getNative<CameraPlugin>(thiz)->image.load(buffer);
	}
}

#endif