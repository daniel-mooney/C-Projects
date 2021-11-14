#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 1000

int *CSV_readline_int(FILE *csv_file);
void CSV_dimensions(FILE *csv_file, int *total_rows, int *total_columns);


int main(void) {

    FILE *csv_fptr = fopen("./data/ordered_number_set.csv", "r");
    
    



    fclose(csv_fptr);

    return 0;
}

int *CSV_readline_int(FILE *csv_file) {
    

}

void CSV_dimensions(FILE *csv_file, int *total_rows, int *total_columns) {

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
    *total_columns = columns;
}