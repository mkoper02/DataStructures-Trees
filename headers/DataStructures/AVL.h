#include "DataStructures/Tree.h"

// Class representing AVL tree
class AVL : public Tree {
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
};