#include "Node.h"
#include <vector>

// Class representing Binary Tree
class Tree {
protected:
    Node* root;         // root of the tree
public:
    // Constructor
    Tree();

    // Add element with given value to the tree
    virtual void add(int value) = 0;

    // Remove element with given value from the tree
    virtual void remove(int value) = 0;

    // Get successor in place of the removed node
    Node* getSuccessor(Node* node);

    // Search for element with given value in the tree and return its address
    Node* find(int value);

    // Search for the lwoest value in the tree and return its address
    Node* minNode(Node* root);

    // Search for the largest value in the tree and return its adress 
    Node* maxNode(Node* root);

    // Root getter
    Node* getRoot() { return root; }

    // Print tree
    void print();

    // Creates array with all nodes from the tree
    // nodes - array to store nodes
    // node - address of the node where function should start
    // node_index - index of the node 
    void indexNodes(std::vector<Node*> &nodes, Node* node, int node_index);
};