#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_BUFF 1000
void visualise_binary(unsigned char binary);

int main() {

    unsigned char bit = 0x60;

    visualise_binary(bit);

    bit >>= 3;
    visualise_binary(bit);



    return 0;
}

void visualise_binary(unsigned char binary) {
    
    char binary_str[] ="00000000";
    unsigned char b1 = 0x01;    // 0000 0001

    for (int i = 7, k = 0; i >= 0; i--, k++) {
        if ( (binary & (b1 << i)) != 0) {
            binary_str[k] = '1';
        }
    }
    printf("%s\n", binary_str);
}