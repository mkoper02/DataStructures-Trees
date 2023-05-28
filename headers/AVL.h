// Class representing node for AVL tree
class Node_AVL {
public:
    int value;          // value of the node
    Node_AVL* left;         // pointer to left child
    Node_AVL* right;        // pointer to right child

public:
    // Default constructor
    Node_AVL();

    // Parameterized constructor
    Node_AVL(int value);
};

// Class representing AVL tree
class AVL {
private:
    Node_AVL* root;         // root of the tree

public:
    // Default constructor, create empty AVL
    AVL();

    // Destructor
    ~AVL();

    // Get height of the given node
    int getHeight(Node_AVL* node);

    // Get balance factor of the given node
    int getBalanceFactor(Node_AVL* node);
};