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
int at_index(int index, linkedList *base);
void free_list(linkedList *base);


int main(int argc, char **argv) {

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

int at_index(int index, linkedList *base) {
    /*Finds the value held at the specified index within the linked list*/
    linkedList *element = base;

    for (int i = 0; i < index; i++) {
        if (element ->next == NULL) {
            printf("Error: Index out of range.");
            exit(0);
        }
        element = element ->next;
    }
    return (element ->value);
}

void free_list(linkedList *base) {
    /*Frees the memory assigned to the the link list starting at the base address*/

    if (base ->next == NULL) {
        free(base);
    } else {
        free_list(base ->next);
        free(base);
    }
}