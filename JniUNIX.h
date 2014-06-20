#ifndef _Include_jni_GIT_
#define _Include_jni_GIT_

#include <jni.h>

//#ifdef _cplusplus
//extern "C" {
//#endif

JNIEXPORT void JNICALL Java_com_jni_UNIX_wc(JNIEnv * env, jobject obj, jstring param, jstring path);
JNIEXPORT void JNICALL Java_com_jni_UNIX_grep(JNIEnv * env, jobject obj, jstring param, jstring path);
JNIEXPORT void JNICALL Java_com_jni_UNIX_invoke(JNIEnv * env, jobject obj, jstring cmd, jstring output_file_path);

//#ifdef _cplusplus
//}
//#endif

#endif
