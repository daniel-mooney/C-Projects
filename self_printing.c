#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *fptr = fopen(__FILE__, "r");
    char ch;

    // Iterate through file char by char
    while (ch != EOF) {
        ch = fgetc(fptr);
        printf("%c", ch);
    }

    fclose(fptr);
}