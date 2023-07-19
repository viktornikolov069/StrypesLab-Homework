#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define TITLE_COUNT 101
#define AUTHOR_COUNT 101
#define BOOK_COUNT 10
#define EPS 0.001

typedef int (*comparator_f)(const void*, const void*);

typedef struct {

    char title[TITLE_COUNT];
    char author[AUTHOR_COUNT];
    uint16_t pages;
    double price;

} Book;

int compareTitleAscending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;

    return strcmp(book1->title, book2->title);
}

int compareTitleDescending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;

    return strcmp(book2->title, book1->title);
}

int comparePagesCountAscending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;
    return book1->pages - book2->pages;
}

int comparePagesCountDescending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;
    return book2->pages - book1->pages;
}

int comparePriceAscending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;

    if(fabs(book1->price - book2->price) < EPS) {
        return 0;
    } else if (book1->price > book2->price) {
        return 1;
    }
    return -1;
}

int comparePriceDescending(const void* value1, const void* value2) {
    Book *book1 = (Book*)value1;
    Book *book2 = (Book*)value2;

    if (fabs(book1->price - book2->price) < EPS) {
        return 0;
    } else if (book2->price > book1->price) {
        return 1;
    }
    return -1;
}

comparator_f getComparator(int n) {
    switch (n) {
        case 1: return compareTitleAscending;
        case 2: return compareTitleDescending;
        case 3: return comparePagesCountAscending;
        case 4: return comparePagesCountDescending;
        case 5: return comparePriceAscending;
        case 6: return comparePriceDescending;
        default: return NULL;
    }
}

int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

char randSymbol(bool isUpper) {
    return isUpper ? randInt('A', 'Z')
                   : randInt('a', 'z');
}

void randTitle(char *str) {
    int len = randInt(10, 21);

    str[0] = randSymbol(true);

    for (int i = 1; i < len; ++i) {
        str[i] = randSymbol(false); 
    }
    str[len] = '\0';
}

void randAuthor(char *str) {
    int len = randInt(3, 11);
    int idx = 0;

    for (int i = 0; i < 2; ++i) {
        str[idx] = randSymbol(true);
        ++idx;
        for (; idx < len; ++idx) {
            str[idx] = randSymbol(false); 
        }
        if (i < 1) {
            str[idx] = ' ';
            len = len*2+1; // including the space
        }
        ++idx;
    }
    str[len] = '\0';
}

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

    //Input Validation
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

    return 0;
}
    