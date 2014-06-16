#ifndef _Include_jni_GIT_
#define _Include_jni_GIT_

#include <jni.h>

//#ifdef _cplusplus
//extern "C" {
//#endif

JNIEXPORT void JNICALL Java_com_jni_GIT_test(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_GIT_log(JNIEnv *, jobject, 
    jstring path, 
    jstring author, 
    jstring since);

//#ifdef _cplusplus
//}
//#endif

#endif
