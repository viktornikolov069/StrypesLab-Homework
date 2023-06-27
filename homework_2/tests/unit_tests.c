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

    runTest(test_isEmpty, "Test isEmpty");


    // uint64_t setA = 251;
    // uint64_t setB = 217;
    // printf("\nresult -> %d\n", isSubset(setA, setB));
    // // printf("\nDifference is %ld", Difference(setA, setB));
    // // printf("")
    // printf("\n251 - 217 = %ld\n", Difference(setA, setB));

    // Run the test functions
    
    // runTest(test_function2, "Test function2");

    // Print test results
    printf("\n--- Test Results ---\n");
    printf("Total tests: %d\n", totalTests);
    printf("Tests passed: %d\n", testsPassed);
    printf("Tests failed: %d\n", testsFailed);



    // for (uint8_t i = 0; i < 64; ++i) {

    // }
    
} 