/*The function defined in this file is able to read a specified column in a file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void grab_file_column(FILE *fptr, int column, char **copy);

int main(void) {

    FILE *fptr = fopen("lorem_ipsum.txt", "r");

    char *column;
    grab_file_column(fptr, 4, &column);      // Reads the 4th column of a file

    printf("%s\n", column);

}

void grab_file_column(FILE *fptr, int column, char **copy) {
    // Reads a specified column of a text file

    char columns[MAX_BUFF];
    char row[MAX_BUFF];

    memset(columns, '\0', MAX_BUFF);
    memset(row, '\0', MAX_BUFF);

    fseek(fptr, 0, SEEK_SET);

    fgets(row, MAX_BUFF, fptr);
    columns[0] = row[column];

    while ( fgets(row, MAX_BUFF, fptr) != NULL) {
        strncat(columns, &row[column], 1);
    }

    *copy = columns;
}