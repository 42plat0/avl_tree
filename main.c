#include "myavltree.c"


int main(){
    Node *root = NULL;
    /* Constructing tree given in the above figure */
    root = ins(root, 10);
    root = ins(root, 20);
    root = ins(root, 30);
    root = ins(root, 25);
    root = ins(root, 40);


    print(root, POST);
    printf("\n");
    root = del(root, 10);

    print(root, POST);
    printf("\n");

    destroyTree(root);
    return 0;
}



