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
    bool passed = false;
    
    // Test case 1
    uint64_t setNotEmpty = 251;
    result = isEmpty(setNotEmpty);
    assert(result == 0 && "251 != 0 -> Test case 1");
    puts("Test case 1 PASSED");

    // Test case 2
    uint64_t setFull = ~0UL;
    result = isEmpty(setNotEmpty);
    assert(result == 0 && "~0UL != 0 -> Test case 2");
    puts("Test case 2 PASSED");

    // Test case 3
    uint64_t setWithOneElement = 1UL;
    result = isEmpty(setWithOneElement);
    assert(result == 0 && "1UL != 0 -> Test case 3");
    puts("Test case 3 PASSED");

    // Test case 4
    uint64_t setEmpty = 0UL;
    result = isEmpty(setEmpty);
    assert(result == 1 && "0UL == 0 -> Test case 4");
    puts("Test case 4 PASSED\n");
    
    passed = true;
    testsPassed++;
}

// Test function for Add
void test_add() {
    uint64_t result = 0;

    // Test case 1
    uint64_t set1 = 0UL;
    result = Add(set1, 0);
    assert(result == 1UL && "Add failed - Test case 1");
    puts("Test case 1 PASSED");

    // Test case 2
    uint64_t set2 = 1UL;
    result = Add(set2, 0);
    assert(result == 1UL && "Add failed - Test case 2");
    puts("Test case 2 PASSED\n");

    testsPassed++;
}

// Test function for Remove
void test_remove() {
    uint64_t result = 0;

    // Test case 1
    uint64_t set1 = 1UL;
    result = Remove(set1, 0);
    assert(result == 0UL && "Remove failed - Test case 1");
    puts("\nTest case 1 PASSED");

    // Test case 2
    uint64_t set2 = 5UL;
    result = Remove(set2, 2);
    assert(result == 1UL && "Remove failed - Test case 2");
    puts("\nTest case 2 PASSED");

    testsPassed++;
}

// Test function for isFull
void test_isFull() {
    char result = 0;
    
    // Test case 1
    uint64_t setFull = ~0UL;
    result = isFull(setFull);
    assert(result == 1 && "isFull failed - Test case 1");
    puts("\nTest case 1 PASSED");

    // Test case 2
    uint64_t setNotFull= 5UL;
    result = isFull(setNotFull);
    assert(result == 0 && "isFull failed - Test case 2");
    puts("\nTest case 2 PASSED");

    testsPassed++;
}

// Test function for isSubset
void test_isSubset() {
    char result = 0;
    uint64_t setA = 251;
    uint64_t setB = 217;
    
    // Test case 1
    result = isSubset(setA, setB);
    assert(result == 1 && "isSubset failed - Test case 1");
    puts("\nTest case 1 PASSED");

    // Test case 2
    result = isSubset(setB, setA);
    assert(result == 0 && "isSubset failed - Test case 2");
    puts("\nTest case 2 PASSED");
    testsPassed++;
}

// Test function for Union
void test_union() {
    uint64_t result = 0;
    
    uint64_t setA = 251;
    uint64_t setB = 217;
    
    // Test case 1
    result = Union(setA, setB);
    assert(result == 251 && "Union failed - Test case 1");
    puts("\nTest case 1 PASSED");
    testsPassed++;

}

// Test function for Intersect
void test_intersect() {
    uint64_t result = 0;
    
    uint64_t setA = 251;
    uint64_t setB = 217;
    
    // Test case 1
    result = Intersect(setA, setB);
    assert(result == 217 && "Intersect failed - Test case 1");
    puts("\nTest case 1 PASSED");
    testsPassed++;
}

// Test function for Difference
void test_difference() {
    uint64_t result = 0;
    
    uint64_t setA = 251;
    uint64_t setB = 217;
    
    // Test case 1
    result = Difference(setA, setB);
    assert(result == 34 && "Difference failed - Test case 1");
    puts("\nTest case 1 PASSED");
    testsPassed++;
}

// Test function for numElements
void test_numElements() {
    char result = 0;
    
    // Test case 1
    uint64_t oneElement = 1;
    result = numElements(oneElement);
    assert(result == 1 && "numElements failed - Test case 1");
    puts("\nTest case 1 PASSED");

    // Test case 2
    uint64_t zeroElements = 0;
    result = numElements(zeroElements);
    assert(result == 0 && "numElements failed - Test case 2");
    puts("\nTest case 2 PASSED");

    // Test case 3
    uint64_t manyElements = 251;
    result = numElements(manyElements);
    assert(result == 7 && "numElements failed - Test case 3");
    puts("\nTest case 3 PASSED");

    testsPassed++;
}

int main() {

    runTest(test_isEmpty, "isEmpty");
    runTest(test_add, "Add");
    runTest(test_remove, "Remove");
    runTest(test_isFull, "isFull");
    runTest(test_isSubset, "isSubset");
    runTest(test_union, "Union");
    runTest(test_intersect, "Intersect");
    runTest(test_difference, "Difference");
    runTest(test_numElements, "numElements");

    printf("\n--- Test Results ---\n");
    printf("Total tests: %d\n", totalTests);
    printf("Tests passed: %d\n", testsPassed);
    printf("Tests failed: %d\n", testsFailed);
} 