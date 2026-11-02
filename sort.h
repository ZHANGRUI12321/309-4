#ifndef SORT_H
#define SORT_H

typedef struct
{
    char id[20];         
    char name[100];      
    char leibie[50];     
    int totalCopies;     
    int availableCopies; 
    int borrowCount;     
} Book;

void sortByBorrowCount(Book books[], int book_count);

#endif