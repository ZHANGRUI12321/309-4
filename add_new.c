#include <stdio.h>
#include <string.h>
#include "add_new.h"

void add_new_book(void)
{
    char id[20];
    char name[100];
    char leibie[50];
    int total;
    int available;
    int borrow = 0; // ???????????0

    // 1. ???????
    int book_count = 0;
    FILE *fp_read = fopen("book.txt", "r");
    if (fp_read != NULL) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp_read) != NULL) {
            if (strlen(buffer) > 1) { // ????
                book_count++;
            }
        }
        fclose(fp_read);
    }
    
    // ?????? B001, B002...
    sprintf(id, "B%03d", book_count + 1);

    // 2. ????
    printf("\n--- ???? ---\n");
    printf("?????: ");
    scanf("%s", name); // ??????????
    printf("?????: ");
    scanf("%s", leibie);
    printf("??????: ");
    scanf("%d", &total);

    // 3. ????
    available = total; // ???? = ???

    // 4. ????
    FILE *fp_write = fopen("book.txt", "a");
    if (fp_write == NULL) {
        printf("???????\n");
        return;
    }

    // ?? 6 ????????????
    fprintf(fp_write, "%s %s %s %d %d %d\n", id, name, leibie, total, available, borrow);
    fclose(fp_write);

    printf("\n?????????????: %s\n", id);
}