#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool isEmpty(uint64_t set) {
    return !!(set) ? false : true;
}

uint64_t Union(int64_t setA, uint64_t setB) {
    return (uint64_t)(setA | setB);
}

uint64_t Intersect(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA & setB);
}

uint64_t Difference(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA ^ setB);
}

char numElements(uint64_t set) {
    char count = 0;
    while (!!(set)) {
        if (set & 1) {  // Check the least significant bit
            count++;
        }
        set >>= 1;  // Shift the bits to the right by 1 position
    }
    return count;
}

bool isSubset(uint64_t setA, uint64_t setB) {
    //Returns 1 if setB is a subset of setA

}




int main() {
    uint64_t set = 0;
    printf("\nresult -> %d\n", numElements(set));

    // for (uint8_t i = 0; i < 64; ++i) {

    // }
    
} 