#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

void printBits(uint64_t set);

void printOperation(uint64_t setA, uint64_t setB, char operation, const char* name);

#endif // UTILS_H