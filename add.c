#include <stdio.h>
#include <string.h>
#define File "book.txt"

int addbook(void)
{
    char name[100];
    char leibie[50];
    int count;
    
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    fgets(leibie, sizeof(leibie), stdin);  
    leibie[strcspn(leibie, "\n")] = 0;
    scanf("%d", &count);
    FILE *fp = fopen("book.txt", "a");
    fprintf(fp, "\n%s %s %d\n", name, leibie, count);
    fclose(fp);
    return 0;
}