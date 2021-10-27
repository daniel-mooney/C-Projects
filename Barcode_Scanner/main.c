#include <stdio.h>
#include <string.h>

#include "bitmap.h"
#include "functions.h"

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

    int frame_numbers[12] = { [0 ... 11 ] -1};

    for (int i = 0; i < image.height; i++) {
        char bin[12];
        create_binary_string(image.pixels[i], bin);
        
        decode_binary(bin, frame_numbers);
    }
    
    if ( !check_valid_barcode(frame_numbers) ) {
        return 0;
    }

    print_decoded_numbers(frame_numbers);

    free_bmp(image);

    return 0;
}