#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "mytime.h"

int main(void){
    time_t rawtime;
    struct tm * timeinfo;

//    int tm_min;
//    int tm_hour;
//    int tm_mday;
//    int tm_mon;
//    int tm_year;
//    int tm_wday;
//    int tm_yday;
//    int tm_isdst;

    printf("time main func.\n");

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("The current data/time is: %s", asctime(timeinfo));

    printf("year=%d\n", timeinfo->tm_year + 1900);
    printf("month=%d\n", timeinfo->tm_mon + 1);
    printf("day=%d\n", timeinfo->tm_mday);
    printf("hour=%d\n", timeinfo->tm_hour);
    printf("minute=%d\n", timeinfo->tm_min);
    printf("second=%d\n", timeinfo->tm_sec);
    printf("day of week=%d\n", timeinfo->tm_wday);
    exit(0);
}
