#include <stdlib.h> //strtod
#include <stdio.h>
#include <math.h> //sqrt

int quadEq(double a, double b, double c, double *x1, double *x2) {

    double D = b*b - 4*a*c;
    if (a == 0) {
        printf("Not a quadratic equation!\n");
        return -1;
    }
    else if (D < 0) {
        printf("No real roots\n");
        return -2;
    }
    else if (D == 0) {
        *x1 = -b / 2*a;
        *x2 = *x1;
    } else {
        *x1 = (-b - sqrt(D)) / 2*a;
        *x2 = (-b + sqrt(D)) / 2*a;
    }
    return 0;
}

// EXAMPLE INPUT: ./quadratic 1 4 -5

// TIP: Don't forget to link the math library explicitly
// gcc quadratic.c -o quadratic -lm 

int main(int argc, char** argv) {

    printf("argc: %d \n", argc);
    if (argc < 4) {
        printf("usage: ./quadratic 1 2 1 ...\n");
        return 0;
    }

    double params[3];
    double x1;
    double x2;

    char *remains;
    int idx = 0;

    for (int i = 1; i < argc; ++i) {
        params[idx] = strtod(argv[i], &remains);
        ++idx;
    }

    int result = quadEq(params[0], params[1], params[2], &x1, &x2);
    if (result == 0) {
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    } 

    return 0;
}