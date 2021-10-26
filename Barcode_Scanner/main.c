#include <stdio.h>
#include <string.h>

#include "bitmap.h"
#include "functions.h"

FILE *create_binary_file(Bmp image, char *filename, char *mode);

int main(int argc, char **argv){

    if (argc < 2) {
        printf("No bmp image filename provided.\n");
        return 0;
    }

    char *filename = argv[1];
    Bmp image = read_bmp(filename);
    
    // Diagnostic mode
    if (argc == 3) {
        printf("Read file %s\n", filename);
        diagnostic_mode(image);
        return 0;
    }

    char bin[12];
    create_binary_string(image.pixels[0], bin);

    int frame_numbers[12] = { [0 ... 11 ] -1};
    decode_binary(bin, frame_numbers);  

    print_decoded_numbers(frame_numbers);

    free_bmp(image);

    return 0;
}

FILE *create_binary_file(Bmp image, char *filename, char *mode) {

    FILE *fptr = fopen(filename, "w");

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            char bin = RBG_to_binary(image.pixels[i][j]);
            fputc(bin, fptr);
        }
        fputc('\n', fptr);
    }
    fclose(fptr);

    fptr = fopen(filename, mode);

    return fptr;
}






