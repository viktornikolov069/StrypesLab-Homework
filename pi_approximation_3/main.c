#include <stdio.h>
#include <assert.h>

#define PI 3.14159f
#define EPS 0.000001f
#define NEGATIVE_EPS -0.000001f

int main() {
    float input;

    printf("Enter a six digit approximation of PI: ");
    scanf("%f", &input);
    const char* answer = ((input - PI < EPS) && (input - PI > NEGATIVE_EPS)) ? "YES" : "NO";
    printf("%s\n", answer);
    return 0;
}