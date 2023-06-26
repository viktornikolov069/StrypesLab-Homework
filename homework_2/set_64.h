#ifndef SET_64_H
#define SET_64_H

#include <stdint.h>
#include <stdbool.h>


bool isEmpty(uint64_t set);

uint64_t Add(uint64_t set, char index);

uint64_t Remove(uint64_t set, char index);

bool isFull(uint64_t set);

bool  isSubset(uint64_t setA, uint64_t setB);

uint64_t Union(uint64_t setA, uint64_t setB);

uint64_t Intersect(uint64_t setA, uint64_t setB);

uint64_t Difference(uint64_t setA, uint64_t setB);

char numElements(uint64_t set);

#endif // SET_64_H

