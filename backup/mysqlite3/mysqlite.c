#include <stdio.h>
#include <sqlite3.h>

int select_callback(void * data, int col_count, char ** col_values, char ** col_name);

int main(void){
    printf("Hello, sqlite3\n");

    int result;
    char * pErrorMsg = 0;
    sqlite3 * db = 0;
    result = sqlite3_open("./age.sqlite", &db);
    if(result != SQLITE_OK){
        printf("无法打开数据库\n");
    }// end if
    printf("打开数据库成功\n");

    // query
    printf("查询全部数据\n");
    sqlite3_exec(db, "select * from friend", select_callback, 0, &pErrorMsg);

    // insert
    printf("插入一条新数据\n");
    sqlite3_exec(db, "insert into friend values(66, 'lichsword', 99);",0 ,0 , &pErrorMsg);
    sqlite3_exec(db, "select * from friend", select_callback, 0, &pErrorMsg);

    // delete
    printf("删除一条数据\n");
    result = sqlite3_exec(db, "delete from friend where id = 66",0 ,0 ,&pErrorMsg);
    if(result == SQLITE_OK){
        printf("删除成功\n");
        sqlite3_exec(db, "select * from friend", select_callback, 0, &pErrorMsg);
    }else{
        printf("删除失败\n");
    }
    
    
    // close
    printf("关闭数据库\n");
    sqlite3_close(db);
}

int select_callback(void * data, int col_count, char ** col_values, char ** col_name){
    int i;
    for(i = 0; i < col_count; i++){
        printf("%s = %s\n", col_name[i], col_values[i]);
    }
    return 0;
}
