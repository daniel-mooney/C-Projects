#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

int main(int argc, char **argv) {
    char* word;
    strcpy(word, "nice");
    
    printf("%s\n", word);
    return 0;
}