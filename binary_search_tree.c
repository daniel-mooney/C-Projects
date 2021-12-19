/*The left side of the binary search tree gravitates towards smaller digits while the right side
gravitates towards larger digits.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;

    struct node *left;
    struct node *right;
};

typedef struct node node;

// Function prototypes
node *add_node(int value, node *base);
void destroy_tree(node *base);

int main(void) {

}

node *add_node(int value, node *base) {
    /*Adds a node to the binary tree, returns the address of the base node.*/
    if (base == NULL) {
        node *new_base = (node *) malloc( sizeof(node) );

        new_base ->value = value;
        new_base ->left = NULL;
        new_base ->right = NULL;

        return new_base;
    }
    // Navigate through tree
    node *new_node = (node *) malloc( sizeof(node) );
    new_node ->value = value;

    if ( base ->left == NULL && base ->right == NULL ) {
        base ->left = new_node;
    } else if ( base ->right ->value >= value) {
        if ( base ->left == NULL ) {
            base ->left = new_node;
        } else {
            add_node(value, base ->left);
        }
    } else {
        if ( base ->right == NULL) {
            base ->right = new_node;
        } else {
            add_node(value, base ->right);
        }
    }
    return base;
}

void destroy_tree(node *base) {
    if ( base ->left != NULL) {
        destroy_tree( base ->left );
    } if ( base ->right != NULL) {
        destroy_tree( base ->right );
    }
    free(base);
}