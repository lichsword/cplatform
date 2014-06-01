#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0

int main(void){
    int result;
    long currentTime;
    long randomValue;
    int input;
    int again = 1;

    currentTime = time(0);
    if(DEBUG){
        printf("当前时间戳%ld", currentTime);
    }// end if

    //srand((unsigned int)currentTime);
    srand(currentTime);
    randomValue= rand();
    result = randomValue % 1000;
    if(DEBUG){
        printf("电脑：生成随机数：%d\n", result);
    }// end if
    
    printf("电脑：生成随机数**\n");
    do{
        printf("人类：");
        scanf("%d", &input);
    
        printf("电脑：");
        if(input == result){
            again = 0;
            printf("猜对了，结果就是%d", result);
        }else if(input > result){
            printf("猜错了，你的数字太大了");
        }else if(input < result){
            printf("猜错了，你的数字太小了");
        }// end if
        printf("\n");
    }while(again);
}
