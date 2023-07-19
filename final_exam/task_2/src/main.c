#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "../include/books.h"

#define BOOK_COUNT 10

int main() {
    srand(time(NULL));
    Book books[BOOK_COUNT];
    
    for (size_t i = 0; i < 10; i++)
    {
        randTitle(books[i].title);
        randAuthor(books[i].author);
        books[i].pages = randInt(10, 1000);
        books[i].price = randReal(2.00, 100.00);
    }

    int option;
    bool optionIsValid = false;
    while (!optionIsValid) {
        scanf("%d", &option);
        if (option < 1 || option > 6) {
            fprintf(stderr, "Not a valid comparator! Enter a number between 1 and 6\n");
        } else {
            optionIsValid = true;
        }
    }
    
    qsort(books, BOOK_COUNT, sizeof(*books), getComparator(option));

    for (size_t i = 0; i < 10; i++)
    {
        printf("%25s %25s %5d %6.2f\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }

    printf("Size of Book structure = %ld bytes\n", sizeof(books[0]));

    return 0;
}