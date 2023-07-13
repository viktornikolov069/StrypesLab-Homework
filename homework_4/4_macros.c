#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
#define SETBIT(mask, bit) ((mask) |= (1ULL << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= ~(1ULL << (bit)))
#define INVERSBIT(mask, bit) ((mask) ^= (1ULL << (bit)))
#define CHECKBIT(mask, bit) !!((mask) &= (1ULL << (bit)))
#define SWAP(a, b) (a) = (a) ^ (b); (b) = (a) ^ (b); (a) = (a) ^ (b)


int main() {

    int a = 533;
    int b = 4;
    int c = 723;

    SWAP(b, c); // b = 723; c = 4;

    printf("Before SWAP b = 4; c = 723\nAfter SWAP:\nb = %d\nc = %d\n\n", b, c);

    int max = MAX(a, b, c); 
    int min = MIN(a, b, c);

    printf("VALUES MAX:\na = %d\nb = %d\nc = %d\nMAX = %d\n\n", a ,b, c, max);
    printf("VALUES MIN:\na = %d\nb = %d\nc = %d\nMIN = %d\n\n", a ,b, c, min);

    int g = 3;
    printf("Initial MASK = %d\n", g);
    SETBIT(g, 3); // g = 11
    CLEARBIT(g, 1); // g = 9
    INVERSBIT(g, 2); // g = 13
    INVERSBIT(g, 2); // g = 9
    printf("MASK after operations = %d\n", g); // g = 9
    printf("CHECKBIT 1 from 9 = %d\n", CHECKBIT(g, 0)); // 9 in binary = 1001 --> bit 1 = 1
    printf("CHECKBIT 2 from 9 = %d\n", CHECKBIT(g, 1)); // 9 in binary = 1001 --> bit 2 = 0

    return 0;
}