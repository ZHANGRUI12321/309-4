#include <stdio.h>
#include "sort.h" 
#include "add.h"
#include "borrow.h"
typedef struct
{
    char id[20];         // 图书编号
    char name[100];      // 图书名称
    char leibie[50];     // 图书类别
    int totalCopies;     // 图书总数量
    int availableCopies; // 当前可借数量
    int borrowCount;     // 历史借阅次数
} Book;

int main()
{
    

    printf("%s\n",jisuan_guihuantime("2026-12-11"));
    printf("%d",dateculculate("2026-12-11","2027-01-10"));
    return 0;
};
