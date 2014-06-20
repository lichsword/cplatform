#include "JniUNIX.h"

#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

JNIEXPORT void JNICALL Java_com_jni_UNIX_invoke(JNIEnv * env, jobject obj, jstring cmd, jstring path){
    
    FILE * cmd_pipe;
    FILE * output_file;
    int read;
    size_t len = 0;
    const int SIZE = 1024;
    char * output_str;
    
    const char * temp_cmd = (*env)->GetStringUTFChars(env, cmd, 0);
    const char * temp_path = (*env)->GetStringUTFChars(env, path, 0);

    printf("%s", temp_cmd);

    cmd_pipe = popen(temp_cmd, "r");

    output_str = (char *)malloc(SIZE);
    memset(output_str, 0, sizeof(SIZE));

    read = getdelim(&output_str, &len, '\0', cmd_pipe);
    output_file = fopen(temp_path, "w+");

    fwrite(output_str, sizeof(char), read, output_file);
    
    (*env)->ReleaseStringUTFChars(env, cmd, temp_cmd); 
    (*env)->ReleaseStringUTFChars(env, path, temp_path); 

    pclose(cmd_pipe);
    fclose(output_file);
}

JNIEXPORT void JNICALL Java_com_jni_UNIX_wc(JNIEnv * env, jobject obj, jstring param, jstring path){

    FILE * wc_pipe;
    FILE * w_file;
    int read;
    size_t len = 0;
    const int SIZE = 1024;
    char * log;
    
    const char part_wc[] = "wc ";
    
    char cmd[SIZE];
    memset(cmd, 0, SIZE);

    const char * temp_param = (*env)->GetStringUTFChars(env, param, 0);
    const char * temp_path = (*env)->GetStringUTFChars(env, path, 0);


    strcpy(cmd, part_wc);
    strcat(cmd, temp_param);
    strcat(cmd, " ");
    strcat(cmd, temp_path);

    printf("%s", cmd);

    wc_pipe = popen(cmd, "r");

    log = (char *)malloc(SIZE);
    memset(log, 0, sizeof(SIZE));

    read = getdelim(&log, &len, '\0', wc_pipe);
    w_file = fopen("wc.log", "w+");

    fwrite(log, sizeof(char), read, w_file);
    
    (*env)->ReleaseStringUTFChars(env, param, temp_param); 
    (*env)->ReleaseStringUTFChars(env, path, temp_path); 

    pclose(wc_pipe);
    fclose(w_file);
}

JNIEXPORT void JNICALL Java_com_jni_UNIX_grep(JNIEnv * env, jobject obj, jstring param, jstring path){

    FILE * wc_pipe;
    FILE * w_file;
    int read;
    size_t len = 0;
    const int SIZE = 1024;
    char * log;
    
    const char part_wc[] = "grep ";
    
    char cmd[SIZE];
    memset(cmd, 0, SIZE);

    const char * temp_param = (*env)->GetStringUTFChars(env, param, 0);
    const char * temp_path = (*env)->GetStringUTFChars(env, path, 0);


    strcpy(cmd, part_wc);
    strcat(cmd, temp_param);
    strcat(cmd, " ");
    strcat(cmd, temp_path);

    printf("%s", cmd);

    wc_pipe = popen(cmd, "r");

    log = (char *)malloc(SIZE);
    memset(log, 0, sizeof(SIZE));

    read = getdelim(&log, &len, '\0', wc_pipe);
    w_file = fopen("wc.log", "w+");

    fwrite(log, sizeof(char), read, w_file);
    
    (*env)->ReleaseStringUTFChars(env, param, temp_param); 
    (*env)->ReleaseStringUTFChars(env, path, temp_path); 

    pclose(wc_pipe);
    fclose(w_file);
}
