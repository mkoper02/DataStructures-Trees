#pragma once

// Class representing node for trees
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