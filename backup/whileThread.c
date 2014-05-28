/**
一个多线程的示例
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ncurses.h>


// define
void *thread_function(void *arg);

WINDOW *new_window_ptr;
WINDOW *popup_window_ptr;
int x_loop;
int y_loop;
char a_letter = 'a';

char message[] = "Hello World";

int main(){
    int res;
    int thread_num;
    pthread_t a_thread;
    void *thread_result_msg;

    //res = pthread_create(&a_thread, NULL, thread_function, (void *)message);

    while(1){
        pthread_create(&a_thread, NULL, thread_function, (void *)message);
        thread_num ++;
	printf("create threads = %d\n", thread_num);
    }
    
    if (res!=0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }// end if

    exit(EXIT_FAILURE);
}



void *thread_function(void *arg){
    sleep(10);
//    strcpy(message, "Bye");
    pthread_exit("Thank you for the CPU time");
}
