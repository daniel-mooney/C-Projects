/*A program that can count from a starting to end number in any based specified (less than 10)
without the use of standard library functions such as itoa.*/

#include <stdio.h>
#include <string.h>

#define MAX_BUFF 1000

void base_counter(int start, int end, int base);
void decimal_to_base(int decimal, int base, char **number);


int main(int argc, char **argv) {
    
    char *number;
    decimal_to_base(83, 5, &number);

    printf("%s\n", number);
    return 0;
}

void base_counter(int start, int end, int base) {

}

void decimal_to_base(int decimal, int base, char **num_str) {
    /*Converts a decimal number to a number of a specified base (less than 10)*/
    char number[MAX_BUFF] = "";

    while (decimal > 0) {
        int quotient = decimal % base;
        char quot_char = quotient + '0';

        strncat(number, &quot_char, 1);
        decimal /= base;
    }
    *num_str = strrev(number);
}
