#include "JniTTY.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

JNIEXPORT void JNICALL Java_com_jni_TTY_echo(JNIEnv * env, jobject obj){
    echo();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_noecho(JNIEnv * env, jobject obj){
    noecho();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_reset(JNIEnv * env, jobject obj){
    system("reset");
}

JNIEXPORT void JNICALL Java_com_jni_TTY_initscr(JNIEnv * env, jobject obj){
    initscr();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_endwin(JNIEnv * env, jobject obj){
    endwin();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_refresh(JNIEnv * env, jobject obj){
    refresh();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_clear(JNIEnv * env, jobject obj){
    clear();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_erase(JNIEnv * env, jobject obj){
    erase();
}
JNIEXPORT void JNICALL Java_com_jni_TTY_cls(JNIEnv * env, jobject obj){
    initscr();// 初始化屏幕
    //clear();// 清屏
    erase();// 清屏
//    move(0, 0);
//    addstr("[debug]cls func...start.");
//    move(LINES-1, 10);
//    addstr("[debug]cls func...end.");
    refresh();// 刷新屏幕
    getch();
    endwin();// 结束屏幕
    return;
}

JNIEXPORT void JNICALL Java_com_jni_TTY_addstr(JNIEnv * env, jobject obj, jstring string){
    char buf[128];
    const char * str = (*env)->GetStringUTFChars(env, string, 0);
    addstr(str);
    (*env)->ReleaseStringUTFChars(env, string, str);
    return;
}

JNIEXPORT void JNICALL Java_com_jni_TTY_move(JNIEnv *env, jobject obj, jint x, jint y){
    move(x, y);
}

JNIEXPORT int JNICALL Java_com_jni_TTY_getch(JNIEnv *env, jobject obj){
    jint ch = getch();
    return ch;
}
