#include <stdio.h>
#include <stdlib.h>//strtod
#include <string.h>
#include <math.h> //sqrt

#define MAX_LENGTH 100

unsigned sumArrayDigits(const int* arr, size_t n) {

    unsigned int lastNum = 0;
    unsigned int result = 0;

    for (size_t i = 0; i < n; ++i) {
        lastNum = arr[i];
        while (lastNum != 0) {
            printf("%d\t", lastNum);
            result += lastNum % 10;
            lastNum /= 10;
            printf("%d\n", lastNum);
        }
    }
    printf("sum = %d\n", result);
    return 0;
}




// EXAMPLE INPUT: 3 4 5 EOF

// TIP: Don't forget to link the math library explicitly
// gcc triangle.c -o triangle -lm 

int main() {
    int arr[] = {1, 11, 1111, 11111 };

    sumArrayDigits(arr, 4);

// 22 

// /1 + 2 + 3 + 4 + 5 + 7 + 0/


    return 0;
}
