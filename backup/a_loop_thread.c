/**
 * 这里中央代码生产中心
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ncurses.h>

// define
void *thread_function(void *arg);

char message[] = "Hello World";

int main(){
    int res;
    int thread_num = 0;
    pthread_t a_thread;
    void *thread_result_msg;

    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if(res!=0){
        perror("Thread creation failed.");
	exit(EXIT_FAILURE);
    }// end if

    printf("Waitting thread finish...");
    res = pthread_join(a_thread, &thread_result_msg);
    if(res!=0){
        perror("Thread join failed.");
	exit(EXIT_FAILURE);
    }// end if

//    while(1){
//        pthread_create(&a_thread, NULL, thread_function, (void *)message);
//        thread_num ++;
//	printf("create threads = %d\n", thread_num);
//    }

    exit(EXIT_FAILURE);
}

void *thread_function(void *arg){
    while(1){
        sleep(10);
	printf("weakup.\n");
    }
//    strcpy(message, "Bye");
    pthread_exit("Thank you for the CPU time");
}
