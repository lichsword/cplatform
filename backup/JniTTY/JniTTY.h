#ifndef _Include_jni_TTY_
#define _Include_jni_TTY_

#include <jni.h>

//#ifdef _cplusplus
//extern "C" {
//#endif

const int MASK_COLOR        = 0x000f;
const int MASK_A_NORMAL     = 0x0010;
const int MASK_A_STANDOUT   = 0x0020;
const int MASK_A_UNDERLINE  = 0x0040;
const int MASK_A_REVERSE    = 0x0080;
const int MASK_A_BLINK      = 0x0100;
const int MASK_A_DIM        = 0x0200;
const int MASK_A_BOLD       = 0x0400;
const int MASK_A_PROTECT    = 0x0800;
const int MASK_A_INVIS      = 0x1000;
const int MASK_A_ALTCHARSET = 0x2000;
const int MASK_A_CHARTEXT   = 0x4000;

JNIEXPORT jlong JNICALL Java_com_jni_TTY_mapAttr(JNIEnv *, jobject, jint);

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
JNIEXPORT void JNICALL Java_com_jni_TTY_attron(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_jni_TTY_attroff(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_jni_TTY_attrset(JNIEnv *, jobject, jint);
JNIEXPORT void JNICALL Java_com_jni_TTY_initPair(JNIEnv *, jobject, jint pair_number, jint foreground, jint background);
JNIEXPORT jint JNICALL Java_com_jni_TTY_getColorPair(JNIEnv *, jobject, jint pair_number);

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrNormal(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrStandout(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrUnderline(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrReverse(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrBlink(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrDim(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrBold(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrProtect(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrInvis(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrAltcharset(JNIEnv *, jobject);
JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrChartext(JNIEnv *, jobject);

JNIEXPORT jint JNICALL Java_com_jni_TTY_getTTYLines(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_com_jni_TTY_getTTYColumns(JNIEnv *, jobject);

//#ifdef _cplusplus
//}
//#endif

#endif
