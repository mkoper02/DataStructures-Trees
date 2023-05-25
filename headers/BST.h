#include <vector>

using namespace std;

// Class representing node for BST
class Node{
public:
    int value;          // value of thenode (key)
    Node* parent;       // pointer to node's parent
    Node* left;         // pointer to left child
    Node* right;        // pointer to right child

public:
    // Default constructor
    Node();

    // Parameterized constructor
    Node(Node* parent, int value);
};

// Class representing Binary Search Tree (BST)
class BST {
private:
    Node* root;         // root of the tree

public:
    // Default constructor, create empty BST
    BST();

    // Constructor, create BST based on given data
    BST(vector<int> elements);

    // Destructor
    ~BST();

    // Add given element to the tree
    void add(int value);

    // Remove given element from the tree
    void remove(int value);

    // Search for element with given value and return its address
    Node* find(int value);

    // Print BST
    void print();

    // Search for the lowest value in the tree and return its address
    Node* minNode(Node* root);

    // Search for the largest value in the tree and return its address 
    Node* maxNode(Node* root);

    // Get successor in place of the removed node
    Node* getSuccessor(Node* node);

    // Root getter
    Node* getRoot() { return root; }
};