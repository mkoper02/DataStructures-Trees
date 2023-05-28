#include "Node.h"

// Class representing AVL tree
class AVL {
private:
    Node* root;         // root of the tree

public:
    // Default constructor, create empty AVL
    AVL();

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
};