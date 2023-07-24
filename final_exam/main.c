#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

#define TITLE_COUNT 101
#define AUTHOR_COUNT 101
#define BOOK_COUNT 10
#define EPS 0.001

typedef int (*comparator_f)(const void*, const void*);

struct Book {

    char title[101];
    char author[101];
    uint16_t pages;
    double price;

};

int main() {
   
   printf("title offset = %ld byte in address structure.\n", offsetof(struct Book, title));

   printf("author offset = %ld byte in address structure.\n", offsetof(struct Book, author));

   printf("pages offset = %ld byte in address structure.\n", offsetof(struct Book, pages));
   printf("price offset = %ld byte in address structure.\n", offsetof(struct Book, price));

   printf("size of book = %ld\n", sizeof(struct Book));

   return(0);
}