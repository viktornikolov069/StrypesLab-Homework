#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void initializeArray(double *arr, int size, double min, double max) {
    for (int i = 0; i < size; i++) {
        arr[i] = randReal(min, max);
    }
}

void printArray(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Invalid number of arguments! Usage: %s n m p\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int p = atoi(argv[3]);

    if (n <= 0 || m <= 0 || p <= 0) {
        fprintf(stderr, "Arguments (n, m, p) must be positive integers.\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation error for initial array.\n");
        return EXIT_FAILURE;
    }

    initializeArray(arr, n, 0.0, 1.0);

    printf("Initial array: ");
    printArray(arr, n);

    double *temp = (double *)realloc(arr, (n + m) * sizeof(double));
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation error for the array with m elements.\n");
        free(arr);
        return EXIT_FAILURE;
    }
    arr = temp;

    initializeArray(arr + n, m, 1.0, 2.0);

    printf("Array after extending with m elements: ");
    printArray(arr, n + m);

    temp = (double *)realloc(arr, (n + m + p) * sizeof(double));
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation error the array with p elements.\n");
        free(arr);
        return 1;
    }
    arr = temp;

    initializeArray(arr + n + m, p, 2.0, 3.0);

    printf("Final array after extending with p elements: ");
    printArray(arr, n + m + p);

    free(arr);

    return 0;
}
