/*The two functions contained in this file combine to be able to read a CSV file of integers one line
at a time, returning an array of the lines contents.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void CSV_readline_int(FILE *csv_file, int *array);
void CSV_dimensions(FILE *csv_file, int *total_rows, int *total_columns);


int main(void) {

    FILE *csv_fptr = fopen("./data/ordered_number_set.csv", "r");

    int row, columns;
    CSV_dimensions(csv_fptr, &row, &columns);

    int array[columns];
    CSV_readline_int(csv_fptr, array);

    for (int i = 0; i < columns; i++) {
        printf("%d\n", array[i]);
    }

    fclose(csv_fptr);
    return 0;
}

void CSV_readline_int(FILE *csv_file, int *array) {
    
    int i = 0;

    char line[MAX_BUFF];
    fgets(line, MAX_BUFF, csv_file);

    char *token = strtok(line, ",");

    while (token != NULL) {
        array[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

void CSV_dimensions(FILE *csv_file, int *total_rows, int *total_columns) {
    // Finds the total rows and columns within a CSV file

    int rows = 0;
    int columns = 0;

    char line[MAX_BUFF];

    while (fgets(line, MAX_BUFF, csv_file)) {
        rows++;

        if (columns == 0) {
            for (int i = 0; i < strlen(line); i++) {
                if (line[i] == ',') {
                    columns++;
                }
            }
        }
    }
    rewind(csv_file);

    *total_rows = rows + 1;
    *total_columns = columns + 1;
}