#pragma once

// Class representing node for BST and AVL
class Node {
public:
    int value;          // value of the node (key)
    Node* parent;       // pointer to node's parent
    Node* left;         // pointer to left child
    Node* right;        // pointer to right child

public:
    // Default constructor
    Node() {
        value = 0;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }

    // Parameterized constructor
    Node(Node* parent, int value) {
        this->parent = parent;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

enum COLOUR { RED = false, BLACK = true };

// Class representing node for Red Black tree
class Node_RB {
public:
    int value;              // value of the node (key)
    Node_RB* parent;        // pointer to node's parent
    Node_RB* left;          // pointer to left child
    Node_RB* right;         // pointer to right child
    COLOUR colour;          // colour of the node (RED/BLACK)

    // Default constructor
    Node_RB() {
        value = 0;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        colour = RED;
    }

    // Parameterized constructor
    Node_RB(Node_RB* parent, int value) {
        this->parent = parent;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};