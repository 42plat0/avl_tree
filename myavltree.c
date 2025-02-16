#include "myavltree.h"

int main(){
    Node* root = createNode(50);
    ins(root, 13);
    ins(root, 60);
    printTreeInOrder(root);
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
    if (root->data > data){
        root->left = ins(root->left, data);
    }
    // Go right if data is bigger than curr node
    else if (root->data < data){
        root->right = ins(root->right, data);
    }

    return root;
}

void printTreeInOrder(Node* root)
{
    if (root != NULL){
        printTreeInOrder(root->left);
        printf("%d ", root->data);        // Need to change it based on datatype that is used
        printTreeInOrder(root->right);
    }
}