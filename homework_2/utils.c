#include <stdio.h>

#include "utils.h"


void printBits(uint64_t set) {
    for (int i = 63; i >= 0; --i) {
        printf("%d", !!(set&(1UL<<i)));
    }
}

void printOperation(char operation) {
    
}