#include <stdio.h>

#include "bitmap.h"
#include "functions.h"

void print_array(unsigned char *arr, FILE *fptr);

int main(void){

    Bmp image = read_bmp("./images/invalid_barcode.bmp");

    create_binary_file(image, "test.txt");



    // FILE *fptr = fopen("bpm_check.txt", "w");

    // for (int i = 0; i < image.height; i++) {
    //     for (int j = 0; j < image.width; j++) {
    //         print_array(image.pixels[i][j], fptr);
    //     }
    //     fputc('\n', fptr);
    // }
    // fclose(fptr);

    return 0;
}

void print_array(unsigned char *arr, FILE *fptr) {

    fputs("[", fptr);

    for (int i = 0; i < 2; i++) {
        fprintf(fptr, "%i, ", arr[i]);
    }
    fprintf(fptr, "%i]", arr[2]);
}





