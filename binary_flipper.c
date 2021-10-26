#include <stdio.h>

unsigned char flip_binary(unsigned char binary);
void visualise_binary(unsigned char binary);

int main() {

    unsigned char byte = 0x37;
    unsigned char flipped_byte = flip_binary(byte);

    printf("byte: ");
    visualise_binary(byte);

    printf("flipped: ");
    visualise_binary(flipped_byte);

    return 0;
}

unsigned char flip_binary(unsigned char binary) {

    int total_bits = sizeof(binary) * 8;
    unsigned char reversed_byte = 0x00;
    unsigned char b1 = 0x01;    // 0000 0001

    for (int i = 0, k = total_bits - 1; i < total_bits; i++, k--) {
        if (binary & (b1 << i)) {
            reversed_byte |= b1 << k;
        }
    }
    return reversed_byte;
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