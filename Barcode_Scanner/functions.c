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

void create_binary_string(unsigned char **pixels, unsigned char *bin_cpy) {

    unsigned char binary[12];
    char byte[8];
    int left_guard;
    int right_guard;

    find_guard_rails(pixels, &left_guard, &right_guard);

    printf("left = %d\t right = %d\n", left_guard, right_guard);
}

char binary_to_char(char *binary) {
    return 'c';
}

void find_guard_rails(unsigned char **pixels, int *left_guard, int *right_guard) {
    // Finds the index of the bits immediately after the left guard and immediately
    // before the right guard.

    char binary[4];
    int i;

    // Find right_guard
    for (i = 0; i < 3; i++) {
        binary[i] = RBG_to_binary(pixels[i]);
    }

    while ( strcmp(binary, "101") != 0) {
        char bit = RBG_to_binary(pixels[i++]);
        shift_arr(binary, 3, bit);
    }
    *left_guard = i;
    memset(binary, '\0', 3);

    // Find left_guard
    for(int k = 0, j = 101; j > 98; k++, j--) {
        binary[k] = RBG_to_binary(pixels[j]);
        i = j;
    }

    while ( strcmp(binary, "101") ) {
        char bit = RBG_to_binary(pixels[i--]);
        shift_arr(binary, 3, bit);
    }
    *right_guard = i;
}

void shift_arr(char arr[], int length, char insert) {

    int i;

    for (i = 1; i < length; i++) {
        arr[i - 1] = arr[i];
    }
    arr[i-1] = insert;
}






