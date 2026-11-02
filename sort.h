// sort.h
#ifndef SORT_H
#define SORT_H

// 把结构体统一放在头文件里，这样大家都能用
typedef struct
{
    char id[20];         
    char name[100];      
    char leibie[50];     
    int totalCopies;     
    int availableCopies; 
    int borrowCount;     
} Book;

// 声明你的排序函数，告诉别人这个函数长什么样
void sortByBorrowCount(Book books[], int book_count);

#endif