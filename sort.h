#ifndef SORT_H
#define SORT_H

// 结构体定义
typedef struct {
    char id[20];
    char name[100];
    char leibie[50];
    int totalCopies;
    int availableCopies;
    int borrowCount;
} Book;

// 声明：无参数，无返回值的打印排行榜函数
void printBooksByBorrowCount();

#endif