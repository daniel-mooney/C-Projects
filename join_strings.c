#include <stdio.h>
#include <string.h>

void join_strings(char **ptr_joined, char *strings[], char *delim);

int main() {

    char *strings[] = {"The", "cow", "is", "a", "fat", "boy", NULL};
    char *sentence;

    join_strings(&sentence, strings, " ");

    printf("%s\n", sentence);

}

void join_strings(char **ptr_joined, char *strings[], char *delim) {
    
    char joined[100000];
    int i = 1;

    strcpy(joined, strings[0]);

    while (strings[i] != NULL) {
        strcat(joined, delim);
        strcat(joined, strings[i++]);
    }
    *ptr_joined = joined;
}