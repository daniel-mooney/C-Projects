#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void strreverse(const char *str, char *reversed);

int main(int argc, char **argv) {
    char *word = "racecar";
    char reversed[MAX_BUFF];

    strreverse(word, reversed);

    printf("%s\n", reversed);
    return 0;
}

void strreverse(const char *str, char *reversed) {
    int i = strlen(str) - 1;
    int j = 0;
    for (; i >= 0; i--, j++) {
        reversed[j] = str[i];
    }
    reversed[j] = '\0';
}