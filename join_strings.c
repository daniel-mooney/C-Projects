/*The function join_strings takes in an array of string literals as an argument along with an delimeter
to join each string within the array by. The string made up of the connected string literal array is assigned
to a variable in main by reference.*/

#include <stdio.h>
#include <string.h>

#define MAX_BUFF 1000

void join_strings(char **ptr_joined, char *strings[], char *delim);

int main(void) {

    char *strings[] = {"The", "cow", "is", "a", "fat", "boy", NULL};
    char *sentence;

    join_strings(&sentence, strings, " ");

    printf("%s\n", sentence);

    return 0;
}

void join_strings(char **ptr_joined, char *strings[], char *delim) {
    
    char joined[MAX_BUFF];
    int i = 1;

    strcpy(joined, strings[0]);

    while (strings[i] != NULL) {
        strcat(joined, delim);
        strcat(joined, strings[i++]);
    }
    *ptr_joined = joined;
}