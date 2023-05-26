// Class representing node for AVL tree
class Node {
public:
    int value;          // value of the node
    Node* left;         // pointer to left child
    Node* right;        // pointer to right child

public:
    // Default constructor
    Node();

    // Parameterized constructor
    Node(int value);
};

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