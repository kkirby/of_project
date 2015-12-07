#include "javaClass.h"

#if defined (TARGET_ANDROID)

size_t allocations;
map<int,JavaClass*> JavaClass::instances;

JavaClass::JavaClass(const char* inputJavaClassName): javaClassName(inputJavaClassName), refid(allocations++) {
	JavaClass::instances.insert(std::pair<int,JavaClass*>(refid,this));
	
	JNIEnv *env = ofGetJNIEnv();
	jclass clazz = getJavaClass();
	jmethodID javaConstructor = JavaClass::getMethodID(clazz,"<init>","I","V");
	if(!javaConstructor){
		ofLogError("JavaClass") << " couldn't find constructor for " << javaClassName << ".\n";
		return;
	}
	javaObject = env->NewObject(clazz,javaConstructor,refid);
	if(!javaObject){
		ofLogError("JavaClass") << " couldn't create instance for " << javaClassName << ".\n";
		return;
	}
	javaObject = (jobject)env->NewGlobalRef(javaObject);
}

JavaClass::~JavaClass(){
	ofGetJNIEnv()->DeleteGlobalRef(javaObject);
	JavaClass::instances.erase(refid);
}

jclass JavaClass::getJavaClass(){
	jclass javaClass = ofGetJNIEnv()->FindClass(javaClassName);
	if(!javaClass){
		ofLogError("JavaObject::getJavaClass") << "unable to find " << javaClassName << " class.";
	}
	return javaClass;
}

// Static

/*static*/ const char* JavaClass::createSignature(const char* params,const char* returnType){
	char* result = new char[strlen(params) + 2 + strlen(returnType)];
	sprintf(result,"(%s)%s",params,returnType);
	return result;
}

//- getMethodID

//--- With class

/*static*/ jmethodID JavaClass::getMethodID(jclass clazz,const char* name,const char* signature){
	return ofGetJNIEnv()->GetMethodID(clazz,name,signature);
}

/*static*/ jmethodID JavaClass::getMethodID(jclass clazz,const char* name,const char* params,const char* returnType){
	return JavaClass::getMethodID(clazz,name,JavaClass::createSignature(params,returnType));
}

//--- With object

/*static*/ jmethodID JavaClass::getMethodID(jobject object,const char* name,const char* signature){
	return JavaClass::getMethodID(ofGetJNIEnv()->GetObjectClass(object),name,signature);
}

/*static*/ jmethodID JavaClass::getMethodID(jobject object,const char* name,const char* params,const char* returnType){
	return JavaClass::getMethodID(ofGetJNIEnv()->GetObjectClass(object),name,params,returnType);
}

//- getFieldID

//--- With class
/*static*/ jfieldID JavaClass::getFieldID(jclass clazz,const char* name,const char* type){
	return ofGetJNIEnv()->GetFieldID(clazz,name,type);
}

//--- With object
/*static*/ jfieldID JavaClass::getFieldID(jobject object,const char* name,const char* type){
	return ofGetJNIEnv()->GetFieldID(ofGetJNIEnv()->GetObjectClass(object),name,type);
}

//-Other

/*static*/ jobject JavaClass::getObjectField(jobject object,const char* fieldName,const char* returnType){
	return ofGetJNIEnv()->GetObjectField(object,JavaClass::getFieldID(object,fieldName,returnType));
}

/*static*/ void JavaClass::setObjectField(jobject object,const char* fieldName,const char* returnType,jobject value){
	ofGetJNIEnv()->SetObjectField(object,JavaClass::getFieldID(object,fieldName,returnType),value);
}

// Members

jmethodID JavaClass::getMethodID(const char* name,const char* signature){
	return JavaClass::getMethodID(javaObject,name,signature);
}

jmethodID JavaClass::getMethodID(const char* name,const char* params,const char* returnType){
	return JavaClass::getMethodID(javaObject,name,params,returnType);
}

jfieldID JavaClass::getFieldID(const char* name,const char* type){
	return JavaClass::getFieldID(javaObject,name,type);
}

jobject JavaClass::getObjectField(const char* fieldName,const char* returnType){
	return JavaClass::getObjectField(javaObject,fieldName,returnType);
}

void JavaClass::setObjectField(const char* fieldName,const char* returnType,jobject value){
	JavaClass::setObjectField(javaObject,fieldName,returnType,value);
}

// Macros

createGetSetFieldMethod(jboolean,Boolean,"Z");
createGetSetFieldMethod(jbyte,Byte,"B");
createGetSetFieldMethod(jchar,Char,"C");
createGetSetFieldMethod(jshort,Short,"S");
createGetSetFieldMethod(jint,Int,"I");
createGetSetFieldMethod(jfloat,Float,"J");
createGetSetFieldMethod(jdouble,Double,"D");

#endif