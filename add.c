#include <stdio.h>
#include <string.h>

int addbook(void)
{
    char name[100];
    char leibie[50];
    int count;
   
    
    printf("璇疯緭鍏ヤ功鍚嶏細");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("璇疯緭鍏ョ被鍒細");
    fgets(leibie, sizeof(leibie), stdin);
    leibie[strcspn(leibie, "\n")] = 0;
    printf("璇疯緭鍏ユ暟閲忥細");
    scanf("%d", &count);
    FILE *fp = fopen("book.txt", "a");
    fprintf(fp, "\n%s %s %d\n", name, leibie, count);
    fclose(fp);
    printf("娣诲姞鎴愬姛锛乗n");
    return 0;
}