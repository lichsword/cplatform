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
char robot_today_weather[] = "Big Rainning. Tip: bring rainbow together when going to work.";
char robot_latest_weibo[] = "3 new friends request; 20 unread messages.";
char robot_gass_back[] = "You wanna backup[bck], I guess.(Y/N)";
char robot_work_backing[] = "Got it, I'll begin backup database, 2 seconds later.";
char robot_may_i_help_you[] = "May I help you, you looks like in coding trouble?";
char robot_sington_code_checking[] = "Sington? I'm checking database...";
char robot_sington_code_found[] = "^_^ I found it!";
char robot_sington_code_display[] = "--------------\npublic class MusicPlayerProxy {\n\n\tprivate static final String TAG = MusicPlayerProxy.class.getSimpleName();\n\n\tprivate static MusicPlayerProxy sInstance;\n\n\tprivate MusicPlayerProxy() {\n\n\t\t// do nothing.\n\t}\n\n\tpublic static MusicPlayerProxy getInstance() {\n\t\tif (null==sInstance) {\n\t\t\tsInstance = new MusicPlayerProx();\n\t\t}// end if\n\t\treturn sInstance;\n\t}\n}";

int main(){
    int res;
    int thread_num;
    pthread_t a_thread;
    void *thread_result_msg;

//    initscr();
//    clear();
//    move(5, 5);
//    printw("%s", "curses lib");
//    refresh();
    
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

//    printf("Waiting for thread to finish...\n");
//    res = pthread_join(a_thread, &thread_result_msg);
//    if(res != 0){
//        perror("Thread join failed");
//        exit(EXIT_FAILURE);
//    }// end if
//
//    printf("Thread joined, it retured %s\n", (char *)thread_result_msg);
//    printf("Message is now %s\n", message);
//
//    endwin();
    exit(EXIT_FAILURE);
}

void speakChar(char ch){
    addch(ch);
    refresh();
    usleep(30000);
}

void speakWord(char *word){
    char *message = (char *)word;
    int len = strlen(message);
    for(int i=0; i<len; i++){
        speakChar(message[i]);
    }
    speakChar(' ');
    usleep(300000);
}

//void speak(char[][10] words){
//    for(int i=0; i<2; i++){
//        speakWord(workds[i]);
//    }
//}

void *thread_function(void *arg){
//    printf("thread_function is running. Argument was %s\n", (char *)arg);
//    char *message = (char *)arg;
//    char[][10] cacheWords = char[5][10];// temp define 5line 10char words cache.

    // divide words
//    int len = strlen(message);
//    int i = 0;
//    int line = 0;
//      int column = 0;
//      for(i=0; i<len; i++){
//          cacheWords[line][column] = message[i];
//          char temp = message[i+1];
//          column++;
//          if(temp==' '){
//              line++;
//              column=0;
//          }// end if
//      }
//      speak(cacheWords);

//    speakWord("Hello wangyue.wy,");
//    speakWord("I'm robot LICHSOWRD");
//    speakWord("who can help you");
//    speakWord("to make your life");
//    speakWord("more happier.");
//    //-----
//    move(6,0);
//    speakWord(robot_today_weather);
//    move(7,0);
//    printw("%s","Fucking rain day. I want see Social Network.");
//    refresh();
//    move(8,0);
//    speakWord(robot_latest_weibo);
//    move(9,0);
//    printw("%s","Rubish information. Database bcked?");
//    refresh();
//    move(10,0);
//    speakWord(robot_gass_back);
//    move(11,0);
//    printw("%s","Y");
//    refresh();
//    move(12,0);
//    speakWord(robot_work_backing);
//    move(13,0);
//    speakWord(robot_may_i_help_you);
//    move(14,0);
//    printw("%s","I'm writing sington code.");
//    refresh();
//    move(15,0);
//    speakWord(robot_sington_code_checking);
//    move(16,0);
//    speakWord(robot_sington_code_found);
//    move(17,0);
//    printw("%s",robot_sington_code_display);
//    refresh();
    // ----window
//    new_window_ptr = newwin(12, 20, 5, 5);
//    mvwprintw(new_window_ptr, 2, 2, "%s", "Hello World");
//    mvwprintw(new_window_ptr, 5, 2, "%s", "Notice how very long lines wrap inside the window");    
//    wrefresh(new_window_ptr);
//    popup_window_ptr = newwin(10, 20, 8, 8);
//    box(popup_window_ptr, '|', '-');
//    mvwprintw(popup_window_ptr, 5, 2, "%s", "Popup window.");
//    wrefresh(popup_window_ptr);

    // --- end win
    sleep(10);
//    strcpy(message, "Bye");
    pthread_exit("Thank you for the CPU time");
}
