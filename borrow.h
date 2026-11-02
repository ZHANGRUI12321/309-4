#ifndef borrow_h
#define borrow_h

char *jisuan_guihuantime(char *borrowtime);
int dateculculate(char *borrowtime,char *guihuantime);
void saveborrow(char *bookname,char *peoplename,char *borrowtime,char *guihuantime);
#endif