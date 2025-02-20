#include <stdio.h>
#include <stdlib.h>

// Define datatype used
typedef int dt;

struct Node {
    dt data;
    struct Node *right;
    struct Node *left;
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

// Prints tree in-order successor - KVD 
void printTreeInOrder(Node*);

// Frees up nodes
void destroyTree(Node*);