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

    // TODO
    char cmd[] = "cd /Users/lichsword/Documents/workspace_company/taoappcenter_android && git log --author='wangyue' --since='1.days' | grep '    '";
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

    pclose(git_pipe); 
    fclose(w_file);
}
