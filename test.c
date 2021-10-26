#include <stdio.h>
#include <math.h>
#include <string.h>

char binary_to_char(char *binary);

int main() {

    char *binary = "1111";
    char bin = binary_to_char(binary);

    char c = 13;

    printf("|%c|\n", c);

    return 0;
}

char binary_to_char(char *byte) {

    char bin_num = 0;
    int length = strlen(byte) - 1;

    for (int i = length, k = 0; i >= 0; i--, k++) {
        int num = byte[i] - '0';
        bin_num += num * pow(2, k);
    }
    return bin_num;
}