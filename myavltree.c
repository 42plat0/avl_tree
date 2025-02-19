#include "myavltree.h"

int main(){
    // Creating the following BST
    //      50
    //     /  \
    //    30   70
    //   / \   / \
    //  20 40 60 80
    //           / \
    //          75  85

    Node* root = createNode(50);
    ins(root, 30);
    ins(root, 20);
    ins(root, 40);
    ins(root, 70);
    ins(root, 60);
    ins(root, 80);
    ins(root, 75);
    ins(root, 87);
    printTreeInOrder(root);
    printf("\n");
    del(root, 70);
    printTreeInOrder(root);
    printf("\n");
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

Node* del(Node* root, dt data){
    // Base case
    if (root == NULL){
        return NULL;
    }

    // Go right if data is bigger than curr node
    if (root->data < data){
        root->right = del(root->right, data);
    }
    // Go left if data is smaller than curr node
    else if(root->data > data){
        root->left = del(root->left, data);
    }
    // Found node to be deleted
    else {
        // has 0 or only right child
        if(root->left == NULL){
            Node* temp = root->right; // Can be valid node or NULL 
            free(root);
            return temp;
        }
        
        // has 0 or only left child
        if(root->right == NULL){
            Node* temp = root->left; // Can be valid node or NULL 
            free(root);
            return temp;
        }

        // has 2 children
        // Replace to-be-deleted node with 
        // leftmost node in right subtree 
        Node* temp = getSuccessor(root->right);
        // Save successor data
        dt saveVal = temp->data; 
        // Delete successor node
        del(root, saveVal);
        // Update node to hold successor data
        root->data = saveVal;
        return root;
    }

    return root;
}

Node* getSuccessor(Node* node)
{
    if(node->left == NULL){
        return node; // Left most node in right subtree
    }
    return getSuccessor(node->left);
}

void printTreeInOrder(Node* root)
{
    if (root != NULL){
        printTreeInOrder(root->left);
        printf("%d ", root->data);        // Need to change it based on datatype that is used
        printTreeInOrder(root->right);
    }
}