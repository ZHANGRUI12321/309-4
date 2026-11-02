#include <stdio.h>
#include <time.h>
int lookname(char *bookname);  //这个函数专门根据书名查是否有这本书，如果有，返回1，如果没有，返回0
int lookcount(char *bookname);  //这个函数专门根据书名查这本书的可借数量，如果有，返回数量，如果没有，返回0
void updatebook(char *bookname,int change);        //功能：这个是修改book.txt文件
void saveborrow(char *bookname,char *peoplename,char *borrowtime,char *guihuantime);      //保存借阅记录的函数
int dateculculate(char *borrowtime,char *guihuantime);  //传入起始时间和最终时间，这个函数可以计算出经过的天数
void borrow()
{
    char choose;
    char bookname[100]; int borrowcount; char peoplename[100];char borrowtime[15];char guihuantime[100];
    printf("请输入借阅书名：");
    scanf("%s", bookname);
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
        printf("可借阅数量为：%d\n",lookcount(bookname));
        printf("是否借阅?(y/n): ");
        scanf(" %c", &choose);
        if(choose=='y')           //字符串用双引号，单个字符用单引号
        {
           printf("请输入借阅数量：");
           scanf("%d\n",&borrowcount);
           printf("请输入借阅人姓名：");
           scanf("%s\n",peoplename);
           printf("请输入借阅日期；(格式;2026-11-01)");        //尽量按照这个日期格式
           scanf("%s\n",borrowtime);
           while(strlen(borrowtime)!=10 || borrowtime[4]!='-' || borrowtime[7]!='-')
           {
            printf("你的日期格式输入错误,严格按照2026-11-01来写");
            scanf("%s\n",borrowtime);
           }
        }
        else
        {
            return;
        }  
        FILE *fp;
        fp=fopen("borrow.txt","a+");
        if(fp==NULL)
        {
            printf("文件打开失败");
            return;
        }
        fprintf(fp,"%s %s %s,%s\n",bookname,peoplename,borrowtime,guihuantime);  //写入借阅txt文件，包括，书名，借阅人和借阅日期
        fclose(fp);
        updatebook(bookname, -borrowcount);  //更新图书数量
    }
 
}
void saveborrow(char *bookname,char *peoplename,char *borrowtime,char *guihuantime)
{
    int havetime=0;
    havetime=guihuantime-borrowtime;
    FILE *fp;
    fp=fopen("borrow.txt","a+");
    if (fp==NULL)
    {
        printf("文件打开失败");
        return;
    }
    fprintf(fp,"%s  %s  %s %s %d\n",bookname,peoplename,borrowtime,guihuantime,havetime);
    fclose(fp);
}
int dateculculate(char *borrowtime,char *guihuantime)
{
    int year1,month1,date1,year2,month2,date2;
    struct tm date={0};
    sscanf(borrowtime,"%d-%d-%d",&year1,&month1,&date1);
    sscanf(guihuantime,"%d-%d-%d",&year2,&month2,&date2);
    

}