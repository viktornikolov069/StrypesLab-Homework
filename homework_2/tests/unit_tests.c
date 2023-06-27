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

// Test function for isEmpty
void test_isEmpty() {
    // Test case 1
    uint64_t setNotEmpty = 251;
    char result = isEmpty(setNotEmpty);
    assert(result == 0);

    // Test case 2
    uint64_t setFull = ~0UL;
    char result = isEmpty(setNotEmpty);
    assert(result == 0);

    // Test case 3
    uint64_t setEmpty = 0UL;
    char result = isEmpty(setNotEmpty);
    assert(result == 1);

    // Test case 4
    uint64_t setWithOneElement = 1UL;
    char result = isEmpty(setWithOneElement);
    assert(result == 1);
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