#include "myavltree.h"

int main(){
    Node* root = createNode(50);
    ins(root, 13);
    ins(root, 60);
    printTreeInOrder(root);
    printf("\n");
    printf(search(root, 19) != NULL ? "Found\n"
                                    : "Not Found\n");
    printf(search(root, 60) != NULL ? "Found\n"
                                    : "Not Found\n");
    return 0;
}

Node* createNode(dt data)
{
    Node* temp = (Node*)malloc(sizeof(Node));

    // Return NULL when not enough memory
    if (temp == NULL)
        return NULL;
    
    // Set data value and pointers
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

Node* ins(Node* root, dt data) 
{
    // Found where to put new node
    if (root == NULL){
        return createNode(data);
    }

    // Value exists
    if (root->data == data)
        return root;

    // Go left if data is smaller than curr node
    // and insert value there
    if (root->data > data){
        root->left = ins(root->left, data);
    }
    // Go right if data is bigger than curr node
    // and insert value there
    else if (root->data < data){
        root->right = ins(root->right, data);
    }

    // do we need this
    return root;
}

Node* search(Node* root, dt data){
    // Value is not found
    if (root == NULL)
        return NULL;

    // Found it
    if (root->data == data)
        return root;

    // Go right if data is bigger than curr node
    if (root->data < data){
        return search(root->right, data);
    }
    // Go left if data is smaller than curr node
    else if(root->data > data){
        return search(root->left, data);
    }
}

void printTreeInOrder(Node* root)
{
    if (root != NULL){
        printTreeInOrder(root->left);
        printf("%d ", root->data);        // Need to change it based on datatype that is used
        printTreeInOrder(root->right);
    }
}