#include <stdio.h>
#include "sort.h"

// 这个函数不需要任何参数，直接干三件事：读文件、排序、打印
void printBooksByBorrowCount() {
    Book books[100];
    int count = 0;
    Book temp;

    // 1. 自动打开文件
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL) {
        printf("无法打开 book.txt，请检查文件是否存在！\n");
        return;
    }

    // 2. 自动读取数据
    while (fscanf(fp, "%s %s %s %d %d %d",
                  books[count].id, books[count].name, books[count].leibie,
                  &books[count].totalCopies, &books[count].availableCopies, &books[count].borrowCount) != EOF) {
        count++;
    }
    fclose(fp);

    // 3. 自动排序（降序）
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (books[j].borrowCount < books[j + 1].borrowCount) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    // 4. 直接输出给用户看
    printf("\n============ 图书借阅排行榜 ============\n");
    printf("%-15s %-20s %s\n", "图书编号", "图书名称", "借阅次数");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-20s %d\n", books[i].id, books[i].name, books[i].borrowCount);
    }
    printf("========================================\n");
}