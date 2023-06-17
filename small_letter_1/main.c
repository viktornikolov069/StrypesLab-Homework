#include <stdio.h>
#include <assert.h>

#define ALPHABET_COUNT 26
#define GAP 6
#define LOWER_CASE_A 'a'
#define LOWER_CASE_Z 'z'

int main() {
    char letter = 0;
    printf("Enter LOWER CASE english letter: \n");
    scanf("%c", &letter);
    assert((letter >= LOWER_CASE_A &&
            letter <= LOWER_CASE_Z) &&
            "Inserted value is not in the allowed range!");

    //The symbols {'[', '\', ']', '^', '_', '`'}, six in count, occupy the gap 
    //bethween the upper and lower case section of the alphabet in the ASKII table.
    //Subtracting the gap and alphabet count from the value of the lower case letter 
    //gives us the desired result.

    printf("Capital letter is \n%c\n", letter-(ALPHABET_COUNT+GAP));
    return 0;
}
