#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define MAX 100000
#define MIN -100000


int main() {
    int32_t number = 0;
    printf("Enter a hole number in the range [-100000, 100000]:\n");
    //SCNd32 is a macro which expands to "d"
    scanf("%" SCNd32, &number); 
    assert((number >= MIN &&
            number <= MAX) &&
            "Inserted value is not in the allowed range!");

    //We are checking if the signed bit is set. 
    //If true the result evaluates to 0 after the 
    //"bitwise and" operation and returns "NO".
    //If false the result is -2^31 which is the lowest possible
    //value in int32_t and returns "YES".
     const char* answer = (number & (1 << 31)) ? "NO" : "YES";
     printf("%s\n", answer);
     printf("%d\n", number & (1 << 31));
     return 0;
}
