#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

// 为了不让 main.c 报错，把结构体搬到这里定义
typedef struct
{
    char id[20];         
    char name[100];      
    char leibie[50];     
    int totalCopies;     
    int availableCopies; 
    int borrowCount;     
} Book;


// 下面是 printBooksByBorrowCount 的完整实现
void printBooksByBorrowCount()
{
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL)
    {
        printf("未找到 book.txt，请先添加数据。\n");
        return;
    }

    Book books[100]; // 假设最多100本书
    int count = 0;
    
    // 从文件中读取数据 (格式需与 add.c 中写入的一致：姓名 类别 次数)
    // 注意：这里假设你的 add.c 里写入的只有这三个字段，如果没有 ID 等，这里只需读这三个
    // 如果你的 txt 里存的是完整结构，需要按对应格式读取
    while (fscanf(fp, "%s %s %d", books[count].name, books[count].leibie, &books[count].borrowCount) != EOF)
    {
        count++;
    }
    fclose(fp);

    if (count == 0)
    {
        printf("数据为空。\n");
        return;
    }

    // 冒泡排序：按借阅次数从高到低
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (books[j].borrowCount < books[j + 1].borrowCount)
            {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    // 打印结果
    printf("%-20s %-15s %-10s\n", "书名", "类别", "借阅次数");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%-20s %-15s %-10d\n", books[i].name, books[i].leibie, books[i].borrowCount);
    }
}