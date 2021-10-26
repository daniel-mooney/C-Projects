#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "bitmap.h"

#define BINARY_FILE "binary.txt"
#define MAX_BUFF 1000


void diagnostic_mode(Bmp bmp_object) {
    printf("Width: %d\n", bmp_object.width);
    printf("Height: %d\n", bmp_object.height);
}

char RBG_to_binary(unsigned char *arr) {

    if( arr[RED] == 255 && arr[GREEN] == 255 && arr[BLUE] == 255) {
        return '0';
    } else if ( arr[RED] == 0 && arr[GREEN] == 0 && arr[BLUE] == 0) {
        return '1';
    }
    return '-';
}







