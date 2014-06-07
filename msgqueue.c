#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>// 线程库
//#include <ncurses.h>// 终端字符库

char message[] = "Hello Thread";

void * thread_func_main(void *);
void * thread_func_back(void *);

int main(void){
    int result;
    pthread_t main_thread;
    void * thread_result_msg;

    printf("Enter main func.\n");
    result = pthread_create(&main_thread, NULL, thread_func_main, (void *)message);
    if(result != 0){
        perror("Thread create...Failed!");
	exit(EXIT_FAILURE);
    }// end if

    printf("Create thread...Success!\n");

    result = pthread_join(main_thread, &thread_result_msg);
    if(result != 0){
        perror("Thread join...Failed!");
	exit(EXIT_FAILURE);
    }// end if

    printf("Launcher receive thread result msg ==> %s\n", thread_result_msg);

    exit(EXIT_SUCCESS);
}

void * thread_func_main(void * arg){
    int result;
    pthread_t back_thread;
    void * thread_result_msg;
    char message[] = "123456789";
    
    printf("Main Thread...Start.\n");
    printf("Receive arg: %s\n", arg);

    result = pthread_create(&back_thread, NULL, thread_func_back, (void *)message);
    if(result != 0){
        perror("Thread create...Failed!");
	exit(EXIT_FAILURE);
    }// end if

    result = pthread_join(back_thread, &thread_result_msg);
    if(result != 0){
        perror("Thread join...Failed!");
	exit(EXIT_FAILURE);
    }// end if

    printf("Main thread receive thread result msg ==> %s\n", thread_result_msg);
    
    printf("Main Thread...End.\n");
    pthread_exit("From Main thread:\n\tThank you for the CPU time!");
}

void * thread_func_back(void * arg){
    printf("Back Thread...Start.\n");
    printf("Receive arg: %s\n", arg);

    
    printf("Back Thread...End.\n");
    pthread_exit("From Back thread:\n\tThank you for the CPU time!");
}
