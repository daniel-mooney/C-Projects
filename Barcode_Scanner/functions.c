#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void create_binary_string(unsigned char **pixels, char *bin_cpy) {

    char binary[13];
    char byte[9];
    int byte_num = 0;
    
    int left_guard;
    int right_guard;

    // Clean binary string
    memset(binary, '\0', 13);

    find_guard_rails(pixels, &left_guard, &right_guard);

    for (int i = left_guard, bit = 0; i < right_guard; i++, bit++) {
        byte[bit] = RBG_to_binary(pixels[i]);

        if (bit == 7) {
            byte[8] = '\0';
            binary[byte_num++] = binary_to_char(byte);
            bit = -1;
        }
    }
    strcpy(bin_cpy, binary);
}

char binary_to_char(char *byte) {

    int bin_num = 0;
    int length = strlen(byte) - 1;

    for (int i = length, k = 0; i >= 0; i--, k++) {
        int num = byte[i] - '0';
        bin_num += num * pow(2, k);
    }
    return bin_num;
}

void find_guard_rails(unsigned char **pixels, int *left_guard, int *right_guard) {
    // Finds the index of the bits immediately after the left guard and immediately
    // before the right guard.

    char binary[4];
    int i;

    // Find left_guard
    for (i = 0; i < 3; i++) {
        binary[i] = RBG_to_binary(pixels[i]);
    }

    while ( strcmp(binary, "101") != 0) {
        char bit = RBG_to_binary(pixels[i++]);
        shift_arr(binary, 3, bit);
    }
    *left_guard = i;
    memset(binary, '\0', 3);

    // Find right_guard
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

void decode_binary(char *binary, int *frame_nums) {

    unsigned char reversed_direction = 0x80;    // 10000000

    // Check if bmp reversed and reverse if required
    if ( binary[0] & reversed_direction ) {
        for (int i = 0; i < 12; i++) {
            binary[i] = flip_binary(binary[i]);
        }
        reverse_string(binary);
    }

    for (int i = 0; i < 12; i++) {
        if ( !valid_parity_bit(binary[i]) ) {
            continue;
        }
        frame_nums[i] = (int) frame_to_int(binary[i]);
    }
    
}

void reverse_string(char *string) {

    int length = strlen(string);
    char rev_str[MAX_BUFF];

    for (int i = 0, k = length - 1; i < length; i++, k--) {
        rev_str[i] = string[k];
    }
    rev_str[length] = '\0';
    strcpy(string, rev_str);
}

unsigned char flip_binary(unsigned char binary) {

    int total_bits = sizeof(binary) * 8;
    unsigned char reversed_byte = 0x00; // 00000000
    unsigned char b1 = 0x01;    // 00000001

    for (int i = 0, k = total_bits - 1; i < total_bits; i++, k--) {
        if (binary & (b1 << i)) {
            reversed_byte |= b1 << k;
        }
    }
    return reversed_byte;
}

int valid_parity_bit(unsigned char byte) {

    unsigned char b1 = 0x01;          // 00000001
    unsigned char bit_scan = 0x03;    // 00000011
    unsigned char MSB_both = 0x60;    // 01100000
    unsigned char LSB_both = 0x0C;    // 00001100

    unsigned char most_sig = byte & (bit_scan << 5);
    unsigned char most_sig_parity = byte & (b1 << 4);
    
    unsigned char least_sig = byte & (bit_scan << 2);
    unsigned char least_sig_parity = byte & (b1 << 1);

    // Check most_sig_parity
    if ( (most_sig == MSB_both || most_sig == 0) && most_sig_parity != 0) {
        return 0;
    } else if ( (most_sig != MSB_both && most_sig != 0) && most_sig_parity == 0 ) {
        return 0;
    }

    // Check least_sig_parity
    if ( (least_sig == LSB_both || least_sig == 0) && least_sig_parity != 0) {
        return 0;
    } else if ( (least_sig != LSB_both && least_sig != 0) && least_sig_parity == 0) {
        return 0;
    }

    return 1;
}

int frame_to_int(unsigned char byte) {
     
    unsigned char bit_scan = 0x03; //00000011

    // Grab most significant and least significant bits
    unsigned char most_sig = byte & (bit_scan << 5);
    most_sig >>= 3;

    unsigned char least_sig = byte & (bit_scan << 2);
    least_sig >>= 2;

    // Decode bits
    int decoded_number = most_sig | least_sig;

    if (decoded_number > 9) {
        decoded_number -= 10;
    }

    return decoded_number;
}

void print_decoded_numbers(int *frame_numbers) {

    int i;

    for (i = 0; i < 11; i++) {
        printf("%d ", frame_numbers[i]);
    }
    printf("%d\n", frame_numbers[i]);
}

int check_valid_barcode (int *frame_numbers) {

    int count = 0;

    for (int i = 0; i < 12; i++) {
        if (frame_numbers[i] == -1) {
            count++;
        }
    }

    if (count == 0) {
        return 1;
    } else if (count == 1) {
        printf("Unable to read frame:");
    } else {
        printf("Unable to read frames:");
    }

    for (int i = 0; i < 12; i++) {
        if (frame_numbers[i] == -1) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}





