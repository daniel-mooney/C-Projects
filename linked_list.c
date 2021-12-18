#include <stdio.h>
#include <stdlib.h>

struct linkedList {
    int value;
    struct linkedList *next;
};

typedef struct linkedList linkedList;

// Function Prototypes
linkedList *create_element(int value);
void add_index(int value, int index, linkedList *base);


int main(void) {

    return 0;
}

linkedList *create_element(int value) {
    /*Initialises a linked list with the base index containing the value of `value`.
    Returns the memory address of the base*/

    linkedList *base = (linkedList *) malloc( sizeof(linkedList) );

    base ->value = value;
    base ->next = NULL;

    return base;
}

void add_index(int value, int index, linkedList *base) {

    linkedList *element = base;
    
    for (int i = 0; (i+1) < index; i++) {
        element = element ->next;

        if (element == NULL) {
            printf("Error: Index out of range.");
            exit(0);
        }
    }
    linkedList *new_element = create_element(value);

    new_element ->next = element ->next;
    element ->next = new_element;    
}