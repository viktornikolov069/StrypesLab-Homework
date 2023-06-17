#include <stdio.h>
#include <inttypes.h>

#define EXEC  1
#define WRITE 2
#define READ  4


int main() {
    uint16_t access_rights = 0;

    //One 1 byte for the leading '-' 
    //9 bytes for the 'X, W, R' charactrers 
    //and 1 byte for the terminating zero
    char result[11] = "----------";
    uint8_t index = 9;

    printf("Enter access rights in octal format (starting with a zero):\n");
    //Saving the entered value directly in octal format for easier manipulation
    scanf("%ho", &access_rights);
    uint8_t permission = 0;

    for (uint8_t i = 0; i < 9; i += 3) {
        //Right shifting with 3 on each iteration will give us the next group of 3 bits
        permission = (access_rights >> i) & 0b111;

        if (permission & EXEC) {
            result[index] = 'X';
        }
        index--;
        if (permission & WRITE) {
            result[index] = 'W';
        }
        index--;
        if (permission & READ) {
            result[index] = 'R';
        }
        index--;
    }

    printf("%s\n", result);
    return 0;
}
