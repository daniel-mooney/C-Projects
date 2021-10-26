#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_BUFF 1000
void reverse_string(char *string);

int main() {

    char word[] = "racecar";

    reverse_string(word);

    printf("%s\n", word);

    return 0;
}

void reverse_string(char *string) {

    int length = strlen(string);
    char rev_str[MAX_BUFF];

    for (int i = 0, k = length - 1; i < length; i++, k--) {
        rev_str[i] = string[k];
    }
    rev_str[length] = '\0';
    strcpy(string, rev_str);
}