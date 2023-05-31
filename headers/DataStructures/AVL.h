#include "DataStructures/Tree.h"

// Class representing AVL tree
class AVL : public Tree<Node> {
public:
    // Default constructor, create empty AVL
    AVL();

    // Constructor, create AVL based on given data
    AVL(std::vector<int> elements);

    // Destructor
    ~AVL();

    // Add element with given value to the tree
    void add(int value);

    // Remove elemnt with given value from the tree
    void remove(int value);

private:
    // Get balance factor of the given node
    int getBalanceFactor(Node* node);

    // Balance tree after adding new node
    void balanceTreeAdd(Node* main_node, Node* new_node);

    // Balance tree after removing node
    void balanceTreeRemove(Node* node);

    // Rotations of the tree
    void leftRotation(Node* node);
    void rightRotation(Node* node);
    void leftRightRotation(Node* node);
    void rightLeftRotation(Node* node);
};