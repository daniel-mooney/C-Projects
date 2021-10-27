#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #include "bitmap.h"

    void diagnostic_mode(Bmp bmp_object);
    char RBG_to_binary(unsigned char *arr);
    void shift_arr(char arr[], int length, char insert);
    void find_guard_rails(unsigned char **pixels, int *left_guard, int *right_guard);
    char binary_to_char(char *binary);
    void create_binary_string(unsigned char **pixels, char *bin_cpy);
    void decode_binary(char *binary, int *frame_nums);
    void reverse_string(char *string);
    unsigned char flip_binary(unsigned char binary);
    int valid_parity_bit(unsigned char byte);
    int frame_to_int(unsigned char byte);
    void print_decoded_numbers(int *frame_numbers);
    int check_valid_barcode (int *frame_numbers);
    
#endif /*FUNCTIONS_H*/
