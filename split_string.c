/*Split string is a re-implementatio of the .split() python function in C. The function takes a character array
as argument and splits the characters by a set delimeter into an array. This array is assigned to a variable
in main by reference.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void split_string(char ***ptr_split, char string[], char *delim);

int main(){

    char string[] = "fun times splitting strings\n";
    string[strcspn(string, "\n")] = 0;

    char **split;

    split_string(&split, string, " ");

    //split[2] = "changed";


    printf("%s\n", split[3]);

    return 0;
}

void split_string(char ***ptr_split, char string[], char *delim) {

    char *split[MAX_BUFF];
    char *token = strtok(string, delim);
    int i = 0;

    while (token != NULL) {
        split[i++] = token;
        token = strtok(NULL, delim);
    }
    split[i] = NULL;
    *ptr_split  = split;
}