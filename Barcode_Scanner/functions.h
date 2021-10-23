#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #include "bitmap.h"

    FILE *create_binary_file(Bmp image, char *filename);
    char RBG_to_binary(unsigned char *arr);
    int *decode_binary(FILE *fptr, int size);


#endif /*FUNCTIONS_H*/
