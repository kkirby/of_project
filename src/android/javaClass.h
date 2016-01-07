#pragma once

#include <ofMain.h>

#if defined (TARGET_ANDROID)

#include <jni.h>
#include "ofxAndroid.h"

// CallMethod

#define createCallMethod(returnType,type,shortType) \
	template<typename... Args> static returnType call ## type ## Method(jobject object,const char* method,const char* params,Args... args){ \
		return ofGetJNIEnv()->Call ## type ## Method(object,JavaClass::getMethodID(object,method,params,shortType),args...); \
	} \
	template<typename... Args> returnType call ## type ## Method(const char* method,const char* params,Args... args){ \
		return JavaClass::call ## type ## Method(javaObject,method,params,args...); \
	}

// GetField

#define createGetFieldMethodHeader(returnType,type) \
	static returnType get ## type ## Field(jobject object,const char* fieldName); \
	returnType get ## type ## Field(const char* fieldName);

#define createGetFieldMethod(returnType,type,shortType) \
	/*static*/ returnType JavaClass::get ## type ## Field(jobject object,const char* fieldName){ \
		return ofGetJNIEnv()->Get ## type ## Field(object,JavaClass::getFieldID(object,fieldName,shortType)); \
	} \
	returnType JavaClass::get ## type ## Field(const char* fieldName){ \
		return JavaClass::get ## type ## Field(javaObject,fieldName); \
	}

// SetField

#define createSetFieldMethodHeader(returnType,type) \
	static void set ## type ## Field(jobject object,const char* fieldName,returnType value); \
	void set ## type ## Field(const char* fieldName,returnType value);

#define createSetFieldMethod(fieldType,type,shortType) \
	/*static*/ void JavaClass::set ## type ## Field(jobject object,const char* fieldName,fieldType value){ \
		ofGetJNIEnv()->Set ## type ## Field(object,JavaClass::getFieldID(object,fieldName,shortType),value); \
	} \
	void JavaClass::set ## type ## Field(const char* fieldName,fieldType value){ \
		JavaClass::set ## type ## Field(javaObject,fieldName,value); \
	}

// GetSet

#define createGetSetFieldMethodHeader(returnType,type) \
	createGetFieldMethodHeader(returnType,type); \
	createSetFieldMethodHeader(returnType,type);

#define createGetSetFieldMethod(returnType,type,shortType) \
	createGetFieldMethod(returnType,type,shortType); \
	createSetFieldMethod(returnType,type,shortType);


class JavaClass {
	private:
		static map<int,JavaClass*> instances;
		size_t refid;
	
	protected:
		const char* javaClassName;
		jobject javaObject;
		jclass getJavaClass();
		
	public:
		JavaClass(const char* javaClassName);
		~JavaClass();
		
		// Static
		
		static const char* createSignature(const char* params,const char* returnType);
		
		static jmethodID getMethodID(jclass clazz,const char* name,const char* signature);
		static jmethodID getMethodID(jclass clazz,const char* name,const char* params,const char* returnType);
		static jmethodID getMethodID(jobject object,const char* name,const char* signature);
		static jmethodID getMethodID(jobject object,const char* name,const char* params,const char* returnType);
		
		static jmethodID getStaticMethodID(jclass clazz,const char* name,const char* signature);
		static jmethodID getStaticMethodID(jclass clazz,const char* name,const char* params,const char* returnType);
		static jmethodID getStaticMethodID(jobject object,const char* name,const char* signature);
		static jmethodID getStaticMethodID(jobject object,const char* name,const char* params,const char* returnType);
		
		static jfieldID getFieldID(jclass clazz,const char* name,const char* type);
		static jfieldID getFieldID(jobject object,const char* name,const char* type);
		
		template<typename... Args> static jobject callObjectMethod(jobject object,const char* method,const char* params,const char* returnType,Args... args){
			return ofGetJNIEnv()->CallObjectMethod(object,JavaClass::getMethodID(object,method,params,returnType),args...);
		}
		
		static jobject getObjectField(jobject object,const char* fieldName,const char* returnType);
		static void setObjectField(jobject object,const char* fieldName,const char* type,jobject value);
		
		// Instance
		
		jmethodID getMethodID(const char* name,const char* signature);
		jmethodID getMethodID(const char* name,const char* params,const char* returnType);
		jfieldID getFieldID(const char* name,const char* type);
		
		template<typename... Args> jobject callObjectMethod(const char* method,const char* params,const char* returnType,Args... args){
			return JavaClass::callObjectMethod(javaObject,method,params,returnType,args...);
		}
		
		jobject getObjectField(const char* fieldName,const char* returnType);
		void setObjectField(const char* fieldName,const char* type,jobject value);	
		
		// Macros
		
		createCallMethod(void,Void,"V");
		createCallMethod(jboolean,Boolean,"Z");
		createCallMethod(jbyte,Byte,"B");
		createCallMethod(jchar,Char,"C");
		createCallMethod(jshort,Short,"S");
		createCallMethod(jint,Int,"I");
		createCallMethod(jfloat,Float,"J");
		createCallMethod(jdouble,Double,"D");
		
		createGetSetFieldMethodHeader(jboolean,Boolean);
		createGetSetFieldMethodHeader(jbyte,Byte);
		createGetSetFieldMethodHeader(jchar,Char);
		createGetSetFieldMethodHeader(jshort,Short);
		createGetSetFieldMethodHeader(jint,Int);
		createGetSetFieldMethodHeader(jfloat,Float);
		createGetSetFieldMethodHeader(jdouble,Double);
		
		template<typename Type> static Type* getNative(jobject object){
			int id = JavaClass::getIntField(object,"refid");
			try {
				return (Type*)JavaClass::instances[id];
			}
			catch(out_of_range e){
				ofLogError("JavaClass") << " couldn't find instance for id " << id << " it has probably been destroyed.\n";
			}
			return nullptr;
		}
};

#endif