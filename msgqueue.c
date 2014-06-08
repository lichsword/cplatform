/**
 * 现在进展：在调用 sem_init 时，发生返回-1失败，网上的说法是 iOS上不支持无名信号量.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>// 信号量
#include <pthread.h>// 线程库
#include <ncurses.h>// 终端字符库
// /usr/local/opt/sqlite/include

sem_t bin_sem;// 信号锁
char message[] = "Hello Thread";
char shareChar;

//void * thread_func_main(void *);
//void * thread_func_back(void *);

void * thread_func_back(void * arg){
    printf("Back Thread...Start.\n");
    printf("Receive arg: %s\n", arg);

    sleep(2);
    sem_post(&bin_sem);
    shareChar = 'a';

    printf("Back Thread...End.\n");
    pthread_exit("From Back thread:\n\tThank you for the CPU time!");
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
        perror("Thread create...Failed!\n");
	exit(EXIT_FAILURE);
    }// end if

    printf("Main Thread: start loop\n");
    while(1){
        sem_wait(&bin_sem);
        printf("Loop work...%c\n", shareChar); 
        
	sleep(1);
    }

    result = pthread_join(back_thread, &thread_result_msg);
    if(result != 0){
        perror("Thread join...Failed!");
	exit(EXIT_FAILURE);
    }// end if

    printf("Main thread receive thread result msg ==> %s\n", thread_result_msg);
    
    printf("Main Thread...End.\n");
    pthread_exit("From Main thread:\n\tThank you for the CPU time!");
}


int main(void){
    int result;
    pthread_t main_thread;
    void * thread_result_msg;

    printf("Enter main func.\n");
    
    result = sem_init(&bin_sem, 0,0);
    if(result != 0){
        printf("result = %d\n", result);
        perror("Semaphore initialization...Failed!\n");
//	exit(EXIT_FAILURE);
    }// end if

    printf("Semaphore init...Success\n");

    result = pthread_create(&main_thread, NULL, thread_func_main, (void *)message);
    if(result != 0){
        perror("Thread create...Failed!\n");
	exit(EXIT_FAILURE);
    }// end if

    printf("Create thread...Success!\n");

    result = pthread_join(main_thread, &thread_result_msg);
    if(result != 0){
        perror("Thread join...Failed!\n");
	exit(EXIT_FAILURE);
    }// end if

    printf("Launcher receive thread result msg ==> %s\n", thread_result_msg);

    sem_destroy(&bin_sem);
    exit(EXIT_SUCCESS);
}

