#include <stdio.h>
#include <stdlib.h>//strtod
#include <string.h>
#include <math.h> //sqrt

#define MAX_LENGTH 100

int triangle(double a, double b, double c, double *S, double *P) {

    if (a <= 0 || b <= 0 || c <= 0)
        return -1;  
    
    if (a + b <= c || b + c <= a || c + a <= b)
        return -1;  
    
    double s = (a + b + c) / 2.0; 
    *P = 2 * s;                   
    *S = sqrt(s * (s - a) * (s - b) * (s - c));
    
    return 0;  
}

// EXAMPLE INPUT: 3 4 5 EOF

// TIP: Don't forget to link the math library explicitly
// gcc triangle.c -o triangle -lm 

int main() {
    char input[MAX_LENGTH];
    double sides[4];
    double S;
    double P;
    
    int index = 0;
    char **remains;
    
    while (scanf("%s", input) != EOF) {
        if (strcmp(input, "EOF") == 0) {
            break;
        }
        sides[index++] = strtod(input, remains);
    }

    int result = triangle(sides[0], sides[1], sides[2], &S, &P);
    if (result == 0) {
        printf("S = %.2lf\n", S);
        printf("P = %.2lf\n", P);
    } else {
        printf("Invalid triangle sides!\n");
    }

    return 0;
}
