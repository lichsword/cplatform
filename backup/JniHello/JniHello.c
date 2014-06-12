#include "JniHello.h"

#include <stdio.h>

JNIEXPORT void JNICALL Java_com_lich_platform_Main_hello(JNIEnv * env, jobject obj){
    printf("Hello JNI!!!\n");
    return;
}

