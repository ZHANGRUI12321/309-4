#include <stdio.h>
#include <string.h>

int deletebook(void)
{
    char bookname[100];
    char line[200];
    
    FILE *bookfile;
    FILE *tempfile;

    printf("请输入要删除的书名：");
    scanf("%99s", bookname);

    bookfile = fopen("book.txt", "r");
    tempfile = fopen("temp.txt", "w");
    
    

}