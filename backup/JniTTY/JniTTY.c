#include "JniTTY.h"

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

JNIEXPORT void JNICALL Java_com_jni_TTY_flash(JNIEnv * env, jobject obj){
    flash();
}

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

JNIEXPORT void JNICALL Java_com_jni_TTY_clrtobot(JNIEnv * env, jobject obj){
    clrtobot();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_clrtoeol(JNIEnv * env, jobject obj){
    clrtoeol();
}

JNIEXPORT void JNICALL Java_com_jni_TTY_erase(JNIEnv * env, jobject obj){
    erase();
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

JNIEXPORT jint JNICALL Java_com_jni_TTY_getch(JNIEnv *env, jobject obj){
    jint ch = getch();
    return ch;
}

JNIEXPORT jstring JNICALL Java_com_jni_TTY_getstr(JNIEnv *env, jobject obj){
    char string[128];
    getstr(string);
    jstring result = (*env)->NewStringUTF(env, string);
    return result;
}

JNIEXPORT jboolean JNICALL Java_com_jni_TTY_hasColors(JNIEnv * env, jobject object){
    return (jboolean)has_colors();
}

JNIEXPORT jint JNICALL Java_com_jni_TTY_startColor(JNIEnv * env, jobject object){
    return (jint) start_color();
}

JNIEXPORT jlong JNICALL Java_com_jni_TTY_mapAttr(JNIEnv * env, jobject jobject, jint value){
   
    jlong result =0;
    jint pair_number = 0;

    pair_number = value & MASK_COLOR;
    result |= COLOR_PAIR(pair_number);
    
    if(value & MASK_A_NORMAL){
        result |= A_NORMAL; 
    }// end if
    if(value & MASK_A_STANDOUT){
        result |= A_STANDOUT; 
    }// end if
    if(value & MASK_A_UNDERLINE){
        result |= A_UNDERLINE; 
    }// end if
    if(value & MASK_A_REVERSE){
        result |= A_REVERSE; 
    }// end if
    if(value & MASK_A_BLINK){
        result |= A_BLINK; 
    }// end if
    if(value & MASK_A_DIM){
        result |= A_DIM; 
    }// end if
    if(value & MASK_A_BOLD){
        result |= A_BOLD; 
    }// end if
    if(value & MASK_A_PROTECT){
        result |= A_PROTECT; 
    }// end if
    if(value & MASK_A_INVIS){
        result |= A_INVIS; 
    }// end if
    if(value & MASK_A_ALTCHARSET){
        result |= A_ALTCHARSET; 
    }// end if
    if(value & MASK_A_CHARTEXT){
        result |= A_CHARTEXT; 
    }// end if

    return result;
}

JNIEXPORT void JNICALL Java_com_jni_TTY_attroff(JNIEnv * env, jobject object, jint value){
    attroff(Java_com_jni_TTY_mapAttr(env, object, value));
}

JNIEXPORT void JNICALL Java_com_jni_TTY_attron(JNIEnv * env, jobject object, jint value){
    attron(Java_com_jni_TTY_mapAttr(env, object, value));
}

JNIEXPORT void JNICALL Java_com_jni_TTY_attrset(JNIEnv * env, jobject object, jint value){
    attrset(Java_com_jni_TTY_mapAttr(env, object, value));
}

JNIEXPORT void JNICALL Java_com_jni_TTY_initPair(JNIEnv * env, jobject object, jint pair_number, jint foreground, jint background){
    init_pair(pair_number, foreground, background);
}

JNIEXPORT jint JNICALL Java_com_jni_TTY_getColorPair(JNIEnv * env, jobject object, jint pair_number){
    return COLOR_PAIR(pair_number);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrNormal(JNIEnv * env, jobject object){
    return (jbyte) (A_NORMAL);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrStandout(JNIEnv * env, jobject object){
    return (jbyte) (A_STANDOUT);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrUnderline(JNIEnv * env, jobject object){
    return (jbyte) (A_UNDERLINE);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrReverse(JNIEnv * env, jobject object){
    return (jbyte) (A_REVERSE);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrBlink(JNIEnv * env, jobject object){
    return (jbyte) (A_BLINK);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrDim(JNIEnv * env, jobject object){
    return (jbyte) (A_DIM);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrBold(JNIEnv * env, jobject object){
    return (jbyte) (A_BOLD);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrProtect(JNIEnv * env, jobject object){
    return (jbyte) (A_PROTECT);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrInvis(JNIEnv * env, jobject object){
    return (jbyte) (A_INVIS);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrAltcharset(JNIEnv * env, jobject object){
    return (jbyte) (A_ALTCHARSET);
}

JNIEXPORT jbyte JNICALL Java_com_jni_TTY_attrChartext(JNIEnv * env, jobject object){
    return (jbyte) (A_CHARTEXT);
}
JNIEXPORT jint JNICALL Java_com_jni_TTY_getTTYLines(JNIEnv * env, jobject object){
    return (jint) LINES;
}
JNIEXPORT jint JNICALL Java_com_jni_TTY_getTTYColumns(JNIEnv * env, jobject object){
    return (jint) COLS;
}
