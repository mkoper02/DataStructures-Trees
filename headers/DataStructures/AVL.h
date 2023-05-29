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

    // Remove elemnt with given value from the tree
    void remove(int value);

    // Balance tree after adding new node
    void balanceTree(Node* main_node, Node* new_node);

    // Rotations of the tree
    void leftRotation(Node* node);
    void rightRotation(Node* node);
    void leftRightRotation(Node* node);
    void rightLeftRotation(Node* node);
};