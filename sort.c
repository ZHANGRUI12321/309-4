#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
#include "book.h" // 使用公共结构体，千万不要再自己定义一遍

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
    char line[512];
    int temp_borrow; // 临时接收“已经借阅”的数字
    
    // 严格按照带中文标签的长格式读取
        while (fgets(line, sizeof(line), fp) != NULL && count < 100)
    {
        if (strlen(line) < 5) continue; // 跳过空行
        
        // 更聪明的读取方式，不强制要求全角冒号
        char *pName = strstr(line, "书名");
        char *pCat = strstr(line, "类别");
        char *pBorrow = strstr(line, "借阅次数");

        if (pName && pCat && pBorrow) {
            sscanf(pName + strlen("书名"), "%*[：:] %s", books[count].name);
            sscanf(pCat + strlen("类别"), "%*[：:] %s", books[count].leibie);
            sscanf(pBorrow + strlen("借阅次数"), "%*[：:] %d", &books[count].borrowCount);
            count++;
        }
    }
    fclose(fp);

    if (count == 0)
    {
        printf("数据为空，或格式读取失败。\n");
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

    // 打印结果：包含索引号、书名、类别、总数、已借阅、剩余、借阅次数
    printf("%-12s %-20s %-12s %-8s %-8s %-8s %-8s\n", "索引号", "书名", "类别", "总数", "已借阅", "剩余", "借阅次数");
    printf("----------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        // 已经借阅 = 总数 - 当前可借数量
        int borrowed = books[i].totalCopies - books[i].availableCopies;
        
        printf("%-12s %-20s %-12s %-8d %-8d %-8d %-8d\n", 
               books[i].id, 
               books[i].name, 
               books[i].leibie, 
               books[i].totalCopies, 
               borrowed, 
               books[i].availableCopies, 
               books[i].borrowCount);
    }
}