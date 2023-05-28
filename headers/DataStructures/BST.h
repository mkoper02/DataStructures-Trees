#include "Node.h"
#include <vector>

// Class representing Binary Search Tree (BST)
class BST {
private:
    Node* root;         // root of the tree

public:
    // Default constructor, create empty BST
    BST();

    // Constructor, create BST based on given data
    BST(std::vector<int> elements);

    // Destructor
    ~BST();

    // Add element with given value to the tree
    void add(int value);

    // Remove element with given value from the tree
    void remove(int value);

    // Search for element with given value and return its address
    Node* find(int value);

    // Print BST
    void print();

    // Search for the lowest value in the tree and return its address
    Node* minNode(Node* root);

    // Search for the largest value in the tree and return its address 
    Node* maxNode(Node* root);

    // Get successor in place of the removed node
    Node* getSuccessor(Node* node);

    // Root getter
    Node* getRoot() { return root; }

    // Creates array with all nodes from the tree
    // nodes - array to store nodes
    // node - address of the node where function should start
    // node_index - index of the node 
    void indexNodes(std::vector<Node*> &nodes, Node* node, int node_index);
};