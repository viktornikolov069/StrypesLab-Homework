#include <stdio.h>
#include <stdlib.h>

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)) {
    printf("sum = %d\n", f(arr, n));
}

int sum(int* arr, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += arr[i];
    }
    return res;
}

int main() {
    int arr[] = {12, 10, 14, 6};

    arrayEvaluate(arr, 4, sum);

    return 0;
}