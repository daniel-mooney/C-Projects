#include <stdio.h>

char *foo(void);

int main() {

    unsigned char word[] = "nice";

    printf("%s\n", word);

    return 0;
}

char *foo(void) {
    char word[] = "abcdefg";
    char *ptr = word;

    return ptr;
}