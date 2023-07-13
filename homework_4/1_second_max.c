#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(double* x, double* y) {
    double temp = *x; 
    *x = *y;
    *y = temp;
}

size_t partition(double array[], size_t low, size_t high) {
    size_t pivot_index = low + (rand() % (high - low));

    if (pivot_index != high) {
        swap(&array[pivot_index], &array[high]);
    }

    double pivot_value = array[high];

    size_t i = low;

    for (size_t j = low; j < high; j++){
        if (array[j] <= pivot_value) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void quicksort_recursion(double array[], size_t low, size_t high) {
    if (low < high) {
        size_t pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

void quicksort(double array[], size_t length) {

    srand(time(NULL));
    
    quicksort_recursion(array, 0, length-1);
}

double secondMax(const double* arr, size_t n) {
    if (!(n & ~0)) {
        printf("Array is empty!");
        return 1;
    }

    if (n == 1) {
        printf("Array has only one element!");
        return 1;
    }

    double arrCopy[n];
    memcpy(arrCopy, arr, n*sizeof(arr[0]));
    quicksort(arrCopy, n);

    if (arrCopy[0] == arrCopy[n-1]) {
        printf("All array elements are the same!");
        return 1;
    }

    for (size_t i = 0; i < n; ++i) {
        printf("%f\n",arrCopy[i]);
    }

    return arrCopy[n-2];
    
    
}

//PROBLEM: This input --- double arr[] = {3, 2.33, 5.33}; --- 
//         causes a segmentation fault.
//         This one works --- double arr[] = {5.11, 2.33, 5.33}; ---

int main() {
    double sm;
    double arr[] = {5.11, 2.33, 5.33};

    sm = secondMax(arr, 3);
    printf("Second Max = %f\n", sm);
    return 0;
}