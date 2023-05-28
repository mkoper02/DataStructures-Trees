#include <vector>

// Class representing node for BST
class Node_BST {
public:
    int value;          // value of the node (key)
    Node_BST* parent;       // pointer to node's parent
    Node_BST* left;         // pointer to left child
    Node_BST* right;        // pointer to right child

public:
    // Default constructor
    Node_BST();

    // Parameterized constructor
    Node_BST(Node_BST* parent, int value);
};

// Class representing Binary Search Tree (BST)
class BST {
private:
    Node_BST* root;         // root of the tree

public:
    // Default constructor, create empty BST
    BST();

    // Constructor, create BST based on given data
    BST(std::vector<int> elements);

    // Destructor
    ~BST();

    // Add given element to the tree
    void add(int value);

    // Remove given element from the tree
    void remove(int value);

    // Search for element with given value and return its address
    Node_BST* find(int value);

    // Print BST
    void print();

    // Search for the lowest value in the tree and return its address
    Node_BST* minNode(Node_BST* root);

    // Search for the largest value in the tree and return its address 
    Node_BST* maxNode(Node_BST* root);

    // Get successor in place of the removed node
    Node_BST* getSuccessor(Node_BST* node);

    // Root getter
    Node_BST* getRoot() { return root; }

    // Creates array with all nodes from the tree
    // nodes - array to store nodes
    // node - address of the node where function should start
    // node_index - index of the node 
    void indexNodes(std::vector<Node_BST*> &nodes, Node_BST* node, int node_index);
};