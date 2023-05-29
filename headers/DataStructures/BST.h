#include "DataStructures/Tree.h"

// Class representing Binary Search Tree (BST)
class BST : public Tree {
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
};