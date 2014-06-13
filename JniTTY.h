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
JNIEXPORT void JNICALL Java_com_jni_TTY_addstr(JNIEnv *, jobject, jstring string);

JNIEXPORT jboolean JNICALL Java_com_jni_TTY_hasColors(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_jni_TTY_startColor(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_com_jni_TTY_attroff(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_jni_TTY_attrset(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_jni_TTY_initPair(JNIEnv *, jobject, jint pair_number, jint foreground, jint background);
JNIEXPORT jint JNICALL Java_com_jni_TTY_getColorPair(JNIEnv *, jobject, jint pair_number);

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrUnderline(JNIEnv *, jobject);

//#ifdef _cplusplus
//}
//#endif

#endif
