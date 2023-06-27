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
    char result = 0;
    
    // Test case 1
    uint64_t setNotEmpty = 251;
    result = isEmpty(setNotEmpty);
    assert(result == 0 && "251 != 0 -> Test case 1");

    // Test case 2
    uint64_t setFull = ~0UL;
    result = isEmpty(setNotEmpty);
    assert(result == 0 && "~0UL != 0 -> Test case 2");

    // Test case 3
    uint64_t setWithOneElement = 1UL;
    result = isEmpty(setWithOneElement);
    assert(result == 0 && "1UL != 0 -> Test case 3");

    // Test case 4
    uint64_t setEmpty = 0UL;
    result = isEmpty(setEmpty);
    assert(result == 1 && "0UL == 0 -> Test case 4");
}

// Test function for Add
void test_add() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
    
}

// Test function for Remove
void test_remove() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for isFull
void test_isFull() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for isSubset
void test_isSubset() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for Union
void test_union() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for Intersect
void test_intersect() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for Difference
void test_difference() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
}

// Test function for numElements
void test_numElements() {
    char result = 0;
    
    // Test case 1
    

    // Test case 2
    

    // Test case 3
    

    // Test case 4
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