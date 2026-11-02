// sort.c
#include "sort.h" // 必须包含这个头文件，才能认识 Book 结构体

// 这里写具体的排序逻辑，注意：不加 int main() 了！
void sortByBorrowCount(Book books[], int book_count) 
{
    Book temp; 
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = 0; j < book_count - 1 - i; j++) {
            if (books[j].borrowCount < books[j + 1].borrowCount) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}