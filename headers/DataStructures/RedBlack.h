#include "DataStructures/Tree.h"

// Class representing Red Black tree
class RedBlack : public Tree<Node_RB> {
public:
    // Default constructor, create empty Red Black tree
    RedBlack();

    // Constructor, create Red Black tree based on given data
    RedBlack(std::vector<int> elements);

    // Destructor
    ~RedBlack();

    // Add element with given value to the tree
    void add(int value);

    // Remove element with given value from the tree
    void remove(int value);

    // Balance tree and fix colours after adding new node
    void balanceTreeAdd(Node_RB* main_node, Node_RB* new_node);

    // Balance tree and fix colours after removing node
    void balanceTreeRemove(Node_RB* node);

    // Rotation of the tree
    void leftRotation(Node_RB* node);
    void rightRotation(Node_RB* node);
    void leftRightRotation(Node_RB* node);
    void rightLeftRotation(Node_RB* node);

    // Change colours where necassary
    void fixColours();
};