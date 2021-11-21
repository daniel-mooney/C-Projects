/*A program that can count from a starting to end number in any based specified (less than 37)
without the use of standard library functions such as itoa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void base_counter(int start, int end, int base);
int decimal_to_base(int decimal, int base, char **number);


int main(int argc, char **argv) {
    
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int base = atoi(argv[3]);

    if (base > 36) {
        printf("base %d is to high!", base);
        return 0;
    }

    base_counter(start, end, base);

    return 0;
}

void base_counter(int start, int end, int base) {
    /*Counts and prints to terminal the numbers from start to end in what ever base specified (less than 37)*/
    int n = start;

    while (n <= end) {
        char *number;
        decimal_to_base(n++, base, &number);

        printf("%s\n", number);
    }
}

int decimal_to_base(int decimal, int base, char **num_str) {
    /*Converts a decimal number to a number of a specified base (less than 37)*/
    char number[MAX_BUFF] = "";

    if (decimal == 0) {
        *num_str = "0";
        return 0;
    }

    while (decimal > 0) {
        int quotient = decimal % base;
        char quot_char = quotient < 10 ? quotient + '0' : quotient + 87;

        strncat(number, &quot_char, 1);
        decimal /= base;
    }
    *num_str = strrev(number);
    return 0;
}