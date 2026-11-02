#include <stdio.h>
int lookname(char *bookname);
int lookcount(char *bookname);
void borrow(char *bookname, int *borrowcount, char *peoplename,char *borrowtime)
{
    if(look(bookname)==0)
    {
        printf("该书不存在,无法借阅")；
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

    }
 
}