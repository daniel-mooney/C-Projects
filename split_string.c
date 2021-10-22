#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_string(char ***ptr_split, char *string, char *delim);

int main(){

    char string[] = "fun times splitting strings";
    char **split;

    split_string(&split, string, "s");

    //split[2] = "changed";

    printf("%s\n", split[3]);

    return 0;
}

void split_string(char ***ptr_split, char string[], char *delim) {

    char *split[10000];
    char *token = strtok(string, delim);
    int i = 0;

    while (token != NULL) {
        split[i++] = token;
        token = strtok(NULL, delim);
    }
    split[i] = NULL;
    *ptr_split  = split;
}