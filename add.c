#include <stdio.h>
#include <string.h>

int addbook(void)
{
    char name[100];
    char leibie[50];
    int count;
   
    
    printf("????????????");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("?????????");
    fgets(leibie, sizeof(leibie), stdin);
    leibie[strcspn(leibie, "\n")] = 0;
    printf("????????????");
    scanf("%d", &count);
    FILE *fp = fopen("book.txt", "a");
    fprintf(fp, "\n%s,%s,%d\n", name, leibie, count);
    fclose(fp);
    printf("????????\n");
    return 0;
}