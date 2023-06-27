#include <stdio.h>
#include <assert.h>
#include "../src/set_64.h"


int totalTests = 0;
int testsPassed = 0;
int testsFailed = 0;

void runTest(void (*testFunc)(), const char* testName) {
    totalTests++;

    printf("Running test: %s\n", testName);
    (*testFunc)();
}

int main() {
    uint64_t setA = 251;
    uint64_t setB = 217;
    printf("\nresult -> %d\n", isSubset(setA, setB));
    // printf("\nDifference is %ld", Difference(setA, setB));
    // printf("")
    printf("\n251 - 217 = %ld\n", Difference(setA, setB));


    // for (uint8_t i = 0; i < 64; ++i) {

    // }
    
} 