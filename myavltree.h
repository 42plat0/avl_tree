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

// Prints tree in-order successor - KVD 
void printTreeInOrder(Node*);