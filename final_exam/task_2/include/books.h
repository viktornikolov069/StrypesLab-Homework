#ifndef BOOKS_H
#define BOOKS_H

#include <stdint.h>

#define TITLE_COUNT 101
#define AUTHOR_COUNT 101

typedef int (*comparator_f)(const void*, const void*);

typedef struct {

    char title[TITLE_COUNT];
    char author[AUTHOR_COUNT];
    uint16_t pages;
    double price;

} Book;

int compareTitleAscending(const void* value1, const void* value2);

int compareTitleDescending(const void* value1, const void* value2);

int comparePagesCountAscending(const void* value1, const void* value2);

int comparePagesCountDescending(const void* value1, const void* value2);

int comparePriceAscending(const void* value1, const void* value2);

int comparePriceDescending(const void* value1, const void* value2);

comparator_f getComparator(int n);

int randInt(int min, int max);

double randReal(double min, double max);

char randSymbol(bool isUpper);

void randTitle(char *str);

void randAuthor(char *str);

#endif //BOOKS_H
    