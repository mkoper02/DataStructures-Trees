#include "Node.h"
#include <vector>

// Class representing AVL tree
class AVL {
private:
    Node* root;         // root of the tree

public:
    // Default constructor, create empty AVL
    AVL();

    // Constructor, create AVL based on given data
    AVL(std::vector<int> elements);

    // Destructor
    ~AVL();

    // Get height of the given node
    int getHeight(Node* node);

    // Get balance factor of the given node
    int getBalanceFactor(Node* node);

    // Add element with given value to the tree
    void add(int value);

    // Search for element with given value and return its address
    Node* find(int value);

    // Root getter
    Node* getRoot() { return root; }

    // Balance tree after adding new node
    void balanceTree(Node* main_node, Node* new_node);

    // Left rotation of the tree
    void leftRotation(Node* node);

    // Right rotation of the tree
    void rightRotation(Node* node);

    // First left then right rotation of the tree
    void leftRightRotation(Node* node);

    // First right then left rotation of the tree
    void rightLeftRotation(Node* node);

    // Print AVL
    void print();

    // Creates array with all nodes from the tree
    // nodes - array to store nodes
    // node - address of the node where function should start
    // node_index - index of the node 
    void indexNodes(std::vector<Node*> &nodes, Node* node, int node_index);
};