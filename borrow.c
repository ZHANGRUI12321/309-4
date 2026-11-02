#include <stdio.h>
int lookname(char *bookname);  //这个函数专门根据书名查是否有这本书，如果有，返回1，如果没有，返回0
int lookcount(char *bookname);  //这个函数专门根据书名查这本书的可借数量，如果有，返回数量，如果没有，返回0
void borrow(char *bookname, int *borrowcount, char *peoplename,char *borrowtime)
{
    if(lookname(bookname)==0)
    {
        printf("该书不存在,无法借阅");
        return;
    }
    else if(lookcount(bookname)==0)
    {
        printf("该书已经被借完啦,无法借阅");
        return;
    }
    else
    {
        FILE *fp;
        fp=fopen("borrow.txt","a+");
        if(fp==NULL)
        {
            printf("文件打开失败");
            return;
        }
        fprintf(fp,"%s %s %s\n",bookname,peoplename,borrowtime);  //写入借阅txt文件，包括，书名，借阅人和借阅日期
        fclose(fp);
    }
 
}