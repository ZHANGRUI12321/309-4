#ifndef book_h
#define book_h

typedef struct
{
    char id[20];         // 图书编号
    char name[100];      // 图书名称
    char leibie[50];     // 图书类别
    int totalCopies;     // 图书总数量
    int availableCopies; // 当前可借数量
    int borrowCount;     // 历史借阅次数
} Book;

#endif