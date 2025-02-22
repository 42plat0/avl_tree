#include "myavltree.h"

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
    updateHeight(root);

    // Get balance of curr node
    int balance = getBalance(root);

    // There are 4 cases of rotation
    if (balance > 1){
        // Left-Left case
        if (root->left->data > data){
            root = rotateRight(root);
        }
        // Left-Right case
        else if (root->left->data < data){ 
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (balance < -1){
        // Right-Right case
        if (root->right->data < data){
            root = rotateLeft(root);
        }
        // Right-left case
        else if (root->right->data > data){
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    // Return node
    // And possibly a new root node after rotation
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
        // return root;
    }
    
    // Update ancestor node height 
    updateHeight(root);

    // Get balance of curr node
    int balance = getBalance(root);

    // There are 4 cases of rotation
    if (balance > 1){
        // Left-Left case
        // Child of imbalanced node has left (or both) child
        if (getBalance(root->left) >= 0){
            root = rotateRight(root);
        }
        // Left-Right case
        // No left child
        else{ 
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }
    }
    else if (balance < -1){
        // Right-Right case
        // Child of imbalanced node has right (or both) child
        if (getBalance(root->right) <= 0){
            root = rotateLeft(root);
        }
        // Right-left case
        // No right child
        else{
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    // Return node
    // And possibly a new root node after rotation
    return root;
}

Node* getSuccessor(Node* node)
{
    if(node->left == NULL){
        return node; // Left most node in right subtree
    }
    return getSuccessor(node->left);
}

void printTree(Node* root, printOrder printOrder)
{
    if (root != NULL){
        switch (printOrder){
            case IO:
                printTree(root->left, printOrder);
                printf(dtFormat, root->data);
                printTree(root->right, printOrder);
                break;
            case PRE:
                printf(dtFormat, root->data);
                printTree(root->left, printOrder);
                printTree(root->right, printOrder);
                break;
            case POST:
                printTree(root->left, printOrder);
                printTree(root->right, printOrder);
                printf(dtFormat, root->data);
                break;
        }
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

Node* rotateRight(Node* root)
{
    // Rotate to right
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    // UPdate hieghts
    updateHeight(root);
    updateHeight(temp);

    return temp;

}

Node* rotateLeft(Node* root)
{
    // Rotate to left 
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    // UPdate hieghts
    updateHeight(root);
    updateHeight(temp);

    return temp;
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

void updateHeight(Node* node)
{
    if (node != NULL)
        node->height = 1 + max(getHeight(node->right), getHeight(node->left));
}

dt max(dt a, dt b)
{
    return (a >= b) ? a : b; 
}

int getBalance(Node* node)
{
    return getHeight(node->left) - getHeight(node->right);
}

