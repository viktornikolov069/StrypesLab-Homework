#include <stdlib.h>
#include <stdio.h>

#include "set_of_64.h"
#include "utils.h"

bool isEmpty(uint64_t set) {
    return !!(set) ? false : true;
}

uint64_t Union(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA | setB);
}

uint64_t Add(uint64_t set, char index) {
    // Bit shift the index 1 << index
    // use & to verify that the element isn't already there !!(set & (1 << index))
    // if the result is zero !!() use | (set | (1 << index))
    // if the result is one maybe give a message that the element exists
    // and return the original value.  
    uint64_t result = !!(set & (1UL << index)) ? set : (set | 1UL << index);
    if (!(result & ~set)) {
        printf("Element is present in set and it can't be added\n");
    }
    printBits(result);
    return result;
}

uint64_t Intersect(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA & setB);
}

uint64_t Difference(uint64_t setA, uint64_t setB) {
    printBits(setB);
    printf(" -> B");
    printf("\n&\n");
    printBits(setA);
    printf(" -> A");
    printf("\n=\n");
    printBits(setA ^ setB);
    //printf("\nIs the intersect the same as setB -> %d\n", !(~(intersect) & setB));
    return (uint64_t)(setA ^ setB);
}

uint64_t Remove(uint64_t set, char index) {
    uint64_t result = !!(Intersect(set, 1UL << index)) ? Difference(set, 1UL << index) : set;
    if (!!(result & ~set)) {
        printf("\nElement is not present in set and there fore it can't be removed\n");
    }
    printf("result -> ");
    printBits(result);
    return result;
}

char numElements(uint64_t set) {
    char count = 0;
    while (!!(set)) {
        if (set & 1UL) {  // Check the least significant bit
            count++;
        }
        set >>= 1UL;  // Shift the bits to the right by 1 position
    }
    return count;
}

//Returns 1 if setB is a subset of setA
bool isSubset(uint64_t setA, uint64_t setB) {
    //
    uint64_t intersect = Intersect(setA, setB);

    // The print functions bellow demonstrate visually how
    // the comparions happens.
    printBits(setB);
    printf(" -> B");
    printf("\n&\n");
    printBits(setA);
    printf(" -> A");
    printf("\n=\n");
    printBits(intersect);
    printf("\nIs the intersect the same as setB -> %d\n", !(~(intersect) & setB));

    // !(~(intersect) & setB) -> with this code we are checking
    // if the intersect is the same as setB. If true then setB is 
    // a subset of setA and all elements of setB are present in setA.
    // If it's false it means that there are elements from setB which
    // are not present in setA.
    return !(~(intersect) & setB) ? true : false;
}

// int main() {
//     uint64_t setA = 251;
//     uint64_t setB = 217;
//     // printf("\nresult -> %d\n", isSubset(setA, setB));
//     // printf("\nDifference is %ld", Difference(setA, setB));
//     // printf("")
//     printf("\n217 - 8 = %ld\n", Remove(setB, 2));


//     // for (uint8_t i = 0; i < 64; ++i) {

//     // }
    
// } 