#include<stdio.h>
void main()
{
    FILE *fp;
    fp=fopen("book.txt","r");
    if(fp==NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    char line[512];

while (fgets(line, sizeof(line), fp) != NULL)
{
    printf("%s", line);
}
}
