#include <stdio.h>

#include "utils.h"


void printBits(uint64_t set) {
    for (int i = 63; i >= 0; --i) {
        printf("%d", !!(set&(1UL<<i)));
    }
}

void printOperation(uint64_t setA, uint64_t setB, char operation, const char* name) {
    printf("\n%s\n", name);
    printBits(setA);
    printf(" -> A\n%c\n", operation);
    printBits(setB);
    printf(" -> B\n=\n");
    switch (operation) {
    case '^':
        printBits(setA ^ setB);
        break;
    case '&':
        printBits(setA & setB);
        break;
    case '|':
        printBits(setA | setB);
        break;
    default:
        break;
    }
}