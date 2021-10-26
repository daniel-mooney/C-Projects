#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #include "bitmap.h"

    void diagnostic_mode(Bmp bmp_object);
    char RBG_to_binary(unsigned char *arr);
    void shift_arr(char arr[], int length, char insert);
    void find_guard_rails(unsigned char **pixels, int *left_guard, int *right_guard);
    char binary_to_char(char *binary);
    void create_binary_string(unsigned char **pixels, char *bin_cpy);
    
#endif /*FUNCTIONS_H*/
