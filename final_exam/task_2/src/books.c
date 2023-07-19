#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "../include/books.h"

#define EPS 0.001

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

