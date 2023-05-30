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
};