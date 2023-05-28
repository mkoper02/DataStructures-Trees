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
};