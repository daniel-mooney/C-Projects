#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF 1000

void CSV_dimensions(FILE *csv_file, int *rows, int *columns);

int main(void) {

    FILE *fptr = fopen("./data/ordered_number_set.csv", "r");

    char line[MAX_BUFF];
    fgets(line, MAX_BUFF, fptr);

    int rows, columns;
    CSV_dimensions(fptr, &rows, &columns);

    printf("%s\n", line);
    printf("%d, %d\n", rows, columns);


    fclose(fptr);

    return 0;
}

void CSV_dimensions(FILE *csv_file, int *total_rows, int *tota_columns) {

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
    *total_rows = rows;
    *tota_columns = columns + 1;
}

