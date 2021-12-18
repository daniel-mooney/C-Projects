#include <stdio.h>
#include <stdlib.h>

struct linkedList {
    int value;
    struct linkedList *next;
};

typedef struct linkedList linkedList;

// Function Prototypes
linkedList *create_element(int value);
linkedList *add_index(int value, int index, linkedList *base);
int at_index(linkedList *base, int index);
void free_list(linkedList *base);


int main(void) {

    linkedList *base =  add_index(8, 0, NULL);
    add_index(2, 1, base);
    add_index(17, 2, base);
    add_index(25, 1, base);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", at_index(base, i));
    }

    free_list(base);

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

linkedList *add_index(int value, int index, linkedList *base) {
    /*Add an element at a given index, if the base is NULL, a new linkedlist is created.
    Returns the memory address of the base element.*/

    linkedList *element = base;
    
    for (int i = 0; (i+1) < index; i++) {
        element = element ->next;

        if (element == NULL) {
            printf("Error: Index out of range.");
            exit(0);
        }
    }
    linkedList *new_element = create_element(value);

    if (index == 0) {
        new_element ->next = base;
        base = new_element;
    } else {
        new_element ->next = element ->next;
        element ->next = new_element; 
    }
    return base;
}

int at_index(linkedList *base, int index) {
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