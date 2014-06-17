#include "JniGIT.h"

#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

JNIEXPORT void JNICALL Java_com_jni_GIT_test(JNIEnv * env, jobject obj){
     system("ls -al > a.txt");
}

JNIEXPORT void JNICALL Java_com_jni_GIT_log(JNIEnv * env, jobject obj, 
    jstring path, 
    jstring author, 
    jstring since){
	
    FILE *git_pipe;
    FILE *w_file;
    int read;
    size_t len = 0;
    const int SIZE = 1024;
    char * log;

    char cmd[SIZE];
    memset(cmd, 0, SIZE);

    const char part_cd[] = "cd ";
    const char part_git_log[] = " && git log ";
    const char part_git_author[] = " --author='";
    const char part_git_since[] = "' --since='";
    const char part_grep[] = "' | grep '    '";

    const char * temp_path = (*env)->GetStringUTFChars(env, path, 0);
    const char * temp_author = (*env)->GetStringUTFChars(env, author, 0);
    const char * temp_since = (*env)->GetStringUTFChars(env, since, 0);

    strcpy(cmd, part_cd);
    strcat(cmd, temp_path);
    strcat(cmd, part_git_log);
    strcat(cmd, part_git_author);
    strcat(cmd, temp_author);
    strcat(cmd, part_git_since);
    strcat(cmd, temp_since);
    strcat(cmd, part_grep);
    
    printf("%s", cmd);

    //初始化buf,以免后面写如乱码到文件中
    log = (char *) malloc (SIZE);
    memset(log, 0, sizeof(SIZE));

    //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
    git_pipe = popen(cmd, "r");
    //新建一个可写的文件
    read = getdelim(&log, &len, '\0', git_pipe);
    w_file = fopen("git.log", "w+");

    //将buf中的数据写到FILE    *wstream对应的流中，也是写到文件中
    fwrite(log, sizeof(char), read, w_file);

    (*env)->ReleaseStringUTFChars(env, path, temp_path);
    (*env)->ReleaseStringUTFChars(env, author, temp_author);
    (*env)->ReleaseStringUTFChars(env, since, temp_since);

    pclose(git_pipe); 
    fclose(w_file);
}
