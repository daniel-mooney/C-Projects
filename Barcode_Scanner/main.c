#include <stdio.h>
#include <string.h>

#include "bitmap.h"
#include "functions.h"

void print_array(unsigned char *arr, FILE *fptr);

int main(int argc, char **argv){

    if (argc < 2) {
        printf("No bmp image filename provided.\n");
        return 0;
    }

    char *filename = argv[1];
    Bmp image = read_bmp(filename);

    printf("Read file %s\n", filename);
    
    // Diagnostic mode
    if (argc == 3) {
        diagnostic_mode(image);
        return 0;
    }

    return 0;
}






