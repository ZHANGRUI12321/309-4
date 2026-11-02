#include <stdio.h>
#include "sort.h" 
#include "add_new.h"

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
    printf("--- 测试添加功能 ---\n");
    add_new_book(); // 测试添加

    printf("\n--- 测试排序打印功能 ---\n");
    printBooksByBorrowCount(); // 测试排序打印
    
    return 0;
};
