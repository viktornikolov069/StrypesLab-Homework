#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int comparator(const void *x_void, const void *y_void) {
    double x = *(double *)x_void;
    double y = *(double *)y_void;

    if (x > y) {
        return 1;
    } else if (x < y) {
        return -1;
    } 
    return 0;
}


double secondMax(const double* arr, size_t n) {
    if (!(n & ~0)) {
        printf("Array is empty!\n");
        return 1;
    }

    if (n == 1) {
        printf("Array has only one element!\n");
        return 2;
    }

    double arrCopy[n];
    memcpy(arrCopy, arr, n*sizeof(double));
    qsort(arrCopy, n, sizeof(double), comparator);

    for (size_t i = 0; i < n; ++i) {
        printf("%f\n", arrCopy[i]);
    }

    return arrCopy[n-2];
}

int main() {
    double sm;
    double arr[] = {3, 2.33, 5.33};

    sm = secondMax(arr, 1 );
    switch ((int)sm) {
    case 1:
        break;
    case 2:
        break;
    default:
        printf("Second Max = %f\n", sm);
        break;
    }

    return 0;
}