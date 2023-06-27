#include <stdlib.h>
#include <stdio.h>

#include "set_64.h"
#include "utils.h"


/**
 * Checks if the set is empty using double not.
 *
 * @param set The set that we do operations on. Expected values are in the range [0, 2^64-1].
 * @return Returns either 1 or 0.
 *         - 1 (true): The set is empty
 *         - 0 (false): The set is not empty
*/
bool isEmpty(uint64_t set) {
    return !!(set) ? false : true;
}

/**
 * Adds an element to a set at the specified index. 
 * 
 * This function adds an element to the given set at the specified index.
 * If the element is already present in the set, it returns the original set
 * without making any modifications. Otherwise, it adds the element to the set
 * and returns the updated set.
 *
 * @param set The original set to which the element will be added. Expected values are in the range [0, 2^64-1].
 * @param index The index at which the element will be added. Expected values are in the range [0, 63].
 * 
 * @return The updated set after adding the element.
*/
uint64_t Add(uint64_t set, char index) {
    uint64_t result = Intersect(set, 1UL << index) ? set : Union(set, 1UL << index);
    if (!Intersect(result, ~set)) {
        printf("Element is present in set and it can't be added\n");
    }
    printBits(result);
    return result;
}

/**
 * Removes an element from a set at the specified index. 
 * 
 * This function removes an element from the given set at the specified index.
 * If the element is already removed in the set, it returns the original set
 * without making any modifications. Otherwise, it removes the element from the set
 * and returns the updated set.
 *
 * @param set The original set from which the element will be removed. Expected values are in the range [0, 2^64-1].
 * @param index The index at which the element will be removed. Expected values are in the range [0, 63].
 * 
 * @return The updated set after adding the element.
*/
uint64_t Remove(uint64_t set, char index) {
    uint64_t result = !!(Intersect(set, 1UL << index)) ? Difference(set, 1UL << index) : set;
    if (!!Intersect(result, ~set)) {
        printf("\nElement is not present in set and there fore it can't be removed\n");
    }
    printf("result -> ");
    printBits(result);
    return result;
}

/**
 * Checks if a set is full.
 *
 * This function determines whether all bits in the given set are set to 1,
 * indicating that the set is full.
 *
 * @param set The set to check. Expected values are in the range [0, 2^64-1].
 * @return True if the set is full (all bits set to 1), false otherwise.
 */
bool isFull(uint64_t set) {
    // Calculate the complement of set using bitwise NOT (~)
    // Then calculate the intersection of the complement and the all-ones set (~0UL)
    // If the intersection is non-zero, it means there are unset bits in the original set
    // If the intersection is zero, it means all bits are set, indicating a full set
    return ~Intersect(~0UL, set) ? false : true;
}

/**
 * Checks if one set is a subset of another set.
 *
 * This function determines whether setB is a subset of setA. A subset is defined as a set
 * where all elements in setB are also present in setA.
 *
 * @param setA The first set to compare. Expected values are in the range [0, 2^64-1].
 * @param setB The second set to compare. Expected values are in the range [0, 2^64-1].
 * @return True if setB is a subset of setA, false otherwise.
 * 
 * @note The way in which a subset is determined is a comparison using bitwise AND
 *       between the intersection(setA, setB) and the supposed subset, setB in this case.
 *       If setB is truly a subset of setA intersection(setA, setB) should return setB.
 *       We verify this by comparing intersection(setA, setB) and setB.
 */
bool isSubset(uint64_t setA, uint64_t setB) {
    //
    uint64_t intersect = Intersect(setA, setB);

    // The print functions bellow demonstrate visually how
    // the comparions happens.
    printOperation(setB, setA, '&', "isSubset");
    printf("\n");
    printf("\nIs the intersect the same as setB -> %d\n", !(~(intersect) & setB));

    return !(~(intersect) & setB) ? true : false;
}

/**
 * Returns the union of two sets.
 *
 * @param setA The first set. Expected values are in the range [0, 2^64-1].
 * @param setB The second set. Expected values are in the range [0, 2^64-1].
 * @return Returns a new set which is the combination of the past two.
 */
uint64_t Union(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA | setB);
}

/**
 * Returns the intersection of two sets.
 *
 * @param setA The first set. Expected values are in the range [0, 2^64-1].
 * @param setB The second set. Expected values are in the range [0, 2^64-1].
 * @return Returns a new set which contains all elements of setA which also belong to setB.
 */
uint64_t Intersect(uint64_t setA, uint64_t setB) {
    return (uint64_t)(setA & setB);
}

/**
 * Returns the difference between two sets.
 *
 * @param setA The first set. Expected values are in the range [0, 2^64-1].
 * @param setB The second set. Expected values are in the range [0, 2^64-1].
 * @return Returns a new set which has elements not part of either setA or setB.
 */
uint64_t Difference(uint64_t setA, uint64_t setB) {
    printOperation(setA, setB, '^', "Difference");
    return (uint64_t)(setA ^ setB);
}

/**
 * Counts the number of elements in a set.
 *
 * @param setA The first set. Expected values are in the range [0, 2^64-1].
 * @return Returns the number of elements.
 * 
 * @note This function counts the bits by modifing the local variable set
 *       with a bit shift to the right.
 */
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