#include <stdio.h>
#include <stdlib.h>

// Print order enum for different print orders
enum printOrder {IO, PRE, POST};
typedef enum printOrder printOrder;

struct Node {
    dt data;
    struct Node *right;
    struct Node *left;
    int height;
};
typedef struct Node Node;

// Create node
Node* createNode(dt);

// Insert Node
Node* ins(Node*, dt);

// Search Node
Node* search(Node*, dt);

// Delete node
Node* del(Node*, dt);

// Get inorder successor
// Needed to delete node with 2 children
// Input is to-be-deleted-node->right
// Output is leftmost node in right subtree 
Node* getSuccessor(Node*);

// Prints tree in order of choosing
// IO = inorder     --- print nodes in left->root ->right order (ASC)  
// PRE = preorder   --- print nodes in root->left ->right order
// POST = postorder --- print nodes in left->right->root  order
void print(Node*, printOrder);

// Frees up nodes
void destroyTree(Node*);

// Rotate node to the right
// And return new root
Node* rotateRight(Node* node);

// Rotate node to the left
// And return new root
Node* rotateLeft(Node* node);

// *****************************
// *******Utility Funcs*********
// *****************************

// Returns max int from two variables
dt max(dt, dt);

// Gets height of node 
// = max(h_left, h_right) + 1
int getHeight(Node*);

// Updates height of given node
void updateHeight(Node*);

// Gets balance factor of given node
int getBalance(Node*);