#include "myavltree.c"


int main(){
    Node *root = NULL;
    /* Constructing tree given in the above figure */
    root = ins(root, 1.85);
    root = ins(root, 2.01);
    root = ins(root, 3.01);
    root = ins(root, 4.01);
    // root = ins(root, 'e');
    print(root, PRE);
    printf("\n");

    destroyTree(root);
    return 0;
}



