#include "myavltree.h"

int main(){
    Node* root = createNode(30);
    ins(root, 20);
    ins(root, 10);

    printTreeInOrder(root);
    printf("\n");
    destroyTree(root);
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
    temp->height = 1;

    return temp;
}

Node* ins(Node* root, dt data) 
{
    // Found where to put a new node
    if (root == NULL){
        return createNode(data);
    }

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
    // Value exists
    else
        return root;

    // Update ancestor node height 
    root->height = 1 + max(getHeight(root->right), getHeight(root->left));

    int balance = getBalance(root);

    printf("Node: %d\n", root->data);
    // printf("%d\n", getBalance(root->left));

    printf("%d\n", balance);

    // There are 4 cases of rotation
    char *str = "";

    // if (balance > 0){
    //     printf("Left was inserted\n");
    // }
    // else{
    //     printf("Right was inserted\n");
    // }
    if (balance > 1){
        // Left-Left case
        if (root->left->data > data)
            str = "Left-Left";
        // Left-Right case
        else if (root->left->data < data)
            str = "Left-Right";

    }
    else if (balance < -1){
        // Right-left case
        if (root->right->data > data)
            str = "Right-Left";
        // Right-Right case
        else if (root->right->data < data)
            str = "Right-Right";
    }

    if (balance > 1 || balance < -1)
    printf("This is %s case\n", str);
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
        printf("%d ", root->data);
        // printf("Node val: %d, height: %d\n", root->data, root->height);        // Need to change it based on datatype that is used
        printTreeInOrder(root->right);
    }
    return;
}

void destroyTree(Node* root)
{
    if (root == NULL){
       return; 
    }

    if (root->left != NULL){
        destroyTree(root->left);
    }
    
    if (root->right != NULL){
        destroyTree(root->right);
    }

    free(root);
    return;
}

// *****************************
// *******Utility Funcs*********
// *****************************

int getHeight(Node* node)
{
    // No subtree is found
    if (node == NULL)
        return 0;

    return node->height;
}

int max(int a, int b)
{
    return (a >= b) ? a : b; 
}

int getBalance(Node* node)
{
    return getHeight(node->left) - getHeight(node->right);
}

