#ifndef _Include_jni_TTY_
#define _Include_jni_TTY_

#include <jni.h>

//#ifdef _cplusplus
//extern "C" {
//#endif

JNIEXPORT void JNICALL Java_com_jni_TTY_flash(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_echo(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_noecho(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_TTY_reset(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_TTY_initscr(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_endwin(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_TTY_refresh(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_TTY_clear(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_erase(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_clrtobot(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_clrtoeol(JNIEnv *, jobject);

JNIEXPORT void JNICALL Java_com_jni_TTY_move(JNIEnv *, jobject, jint, jint);
JNIEXPORT jint JNICALL Java_com_jni_TTY_getch(JNIEnv *, jobject);
JNIEXPORT jstring JNICALL Java_com_jni_TTY_getstr(JNIEnv *, jobject);
/**
 * class: com.jni.TTY
 * method: addstr
 */
JNIEXPORT void JNICALL Java_com_jni_TTY_addstr(JNIEnv *, jobject, jstring string);
/**
 * class: com.jni.TTY
 * method: cls
 */
JNIEXPORT void JNICALL Java_com_jni_TTY_cls(JNIEnv *, jobject);

//#ifdef _cplusplus
//}
//#endif

#endif
