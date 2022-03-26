/*The function visualise_binary takes in one byte worth of information in the form of a character and is 
able to print the underlying binary to the terminal.

Pass binary in as a Hex value through*/

#include <stdio.h>
#include <stdlib.h>

void visualise_byte(unsigned char binary);

int main(int argc, char **argv) {

    unsigned char binary = strtol(argv[1], NULL, 16);   // Convert string hex into binary

    visualise_byte(binary);

    return 0;
}

void visualise_byte(unsigned char binary) {
    
    char binary_str[] ="00000000";
    unsigned char b1 = 0x01;    // 0000 0001

    for (int i = 7, k = 0; i >= 0; i--, k++) {
        if ( (binary & (b1 << i)) != 0) {
            binary_str[k] = '1';
        }
    }
    printf("%s\n", binary_str);
}