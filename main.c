// Firstly,
// Define datatypes used in AVL tree
// Be sure that they match
typedef float dt;
#define dtFormat "%f "

// Include library
#include "myavltree.c"

int main(){
    // Initialize root
    Node *root = NULL;
    // Insert values
    // Reassign root
    root = ins(root, 10.112);
    root = ins(root, 12.20);
    root = ins(root, 25.1953);
    root = ins(root, 100.35);

    // Print tree 
    printTree(root, PRE);
    printf("\n");

    // Delete root val
    root = del(root, 12.20);

    // Print tree 
    printTree(root, PRE);
    printf("\n");
    
    // Free up memory
    destroyTree(root);
    return 0;
}



