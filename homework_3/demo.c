#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    double a = 0.1f;
    if (!((unsigned int)a & 0)) {
        printf("It's zero");
    }
    
    return 0;
}
