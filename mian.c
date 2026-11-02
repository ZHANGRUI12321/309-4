#include <stdio.h>
#include <string.h>

// 1. 定义结构体
typedef struct
{
    char id[20];         
    char name[100];      
    char leibie[50];     
    int totalCopies;     
    int availableCopies; 
    int borrowCount;     // 历史借阅次数
} Book;

int main()
{
    Book books[100]; // 书架
    int book_count = 0; // 实际书本数量
    
    // 2. 打开文件并读取
    FILE *fp = fopen("book.txt", "r"); 
    if (fp == NULL) {
        printf("打不开 book.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s %d %d %d",
                  books[book_count].id, books[book_count].name, books[book_count].leibie,
                  &books[book_count].totalCopies, &books[book_count].availableCopies, &books[book_count].borrowCount) != EOF) {
        book_count++;
    }
    fclose(fp);

    // 3. 【最简单的排序：冒泡排序】按借阅次数从大到小排
    Book temp; // 用来交换的临时空盒子
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - 1 - i; j++) {
            // 如果前面那本书的借阅次数，比后面那本书少
            if (books[j].borrowCount < books[j + 1].borrowCount) {
                // 把两本书的位置换一下（把借阅次数多的换到前面去）
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    // 4. 打印结果
    printf("============ 图书借阅排行榜 ============\n");
    for (int i = 0; i < book_count; i++) {
        printf("书名: %s, 借阅次数: %d\n", books[i].name, books[i].borrowCount);
    }

    return 0; 
}