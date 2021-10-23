#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "bitmap.h"

FILE *create_binary_file(Bmp image, char *filename) {

    FILE *fptr = fopen(filename, "w");

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            char bin = RBG_to_binary(image.pixels[i][j]);
            fputc(bin, fptr);
        }
        fputc('\n', fptr);
    }
    fclose(fptr);

    return fptr;
}

char RBG_to_binary(unsigned char *arr) {

    if( arr[RED] == 255 && arr[GREEN] == 255 && arr[BLUE] == 255) {
        return '0';
    } else if ( arr[RED] == 0 && arr[GREEN] == 0 && arr[BLUE] == 0) {
        return '1';
    }
    return '-';
}

int *decode_binary(FILE *fptr, int size) {
    
}


