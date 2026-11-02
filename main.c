#include <stdio.h>
#include "sort.h" 
#include "add.h"
#include "borrow.h"
#include "book.h"
int main()
{
    

    printf("%s\n",jisuan_guihuantime("2026-12-11"));
    printf("%d",dateculculate("2026-12-11","2027-01-10"));
    saveborrow("红与黑","周玉影","2026-12-11","2027-01-10");
    return 0;
};
