#include <stdio.h>
#include <string.h>
#include "add_new.h"

void add_new_book(void)
{
    char id[20];
    char name[100];
    char leibie[50];
    int total;
    int available;
    int borrow = 0; // 新书初始借阅次数强制为0

    // 1. 自动生成索引号
    int book_count = 0;
    FILE *fp_read = fopen("book.txt", "r");
    if (fp_read != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp_read) != NULL) {
            if (strlen(buffer) > 1) { // 排除空行
                book_count++;
            }
        }
        fclose(fp_read);
    }
    
    // 自动生成编号 B001, B002...
    sprintf(id, "B%03d", book_count + 1);

    // 2. 用户输入
    printf("\n--- 添加新书 ---\n");
    printf("请输入书名: ");
    scanf("%s", name); // 注意：书名不能带空格
    printf("请输入类别: ");
    scanf("%s", leibie);
    printf("请输入总数量: ");
    scanf("%d", &total);

    // 3. 自动计算
    available = total; // 可借数量 = 总数量

    // 4. 写入文件
    FILE *fp_write = fopen("book.txt", "a");
    if (fp_write == NULL) {
        printf("文件打开失败！\n");
        return;
    }

    // 按照 6 个字段的格式写入，并换行
    fprintf(fp_write, "%s %s %s %d %d %d\n", id, name, leibie, total, available, borrow);
    fclose(fp_write);

    printf("\n添加成功！系统自动分配编号: %s\n", id);
}