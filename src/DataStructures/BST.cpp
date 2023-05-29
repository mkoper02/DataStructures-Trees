#include "DataStructures/BST.h"
#include <iostream>
#include <math.h>

BST::BST() : Tree() {}

BST::BST(std::vector<int> elements) : BST() {
    if (elements.empty()) return;

    for (auto element : elements) {
        add(element);
    }
}

BST::~BST() {
    while (root != nullptr) {
        remove(root->value);
    }
}

void BST::add(int value) {
    // Dont allow nodes with the same value
    if (find(value) != nullptr) return;

    // If BST is empty new value becomes root
    if (root == nullptr) {
        root = new Node(nullptr, value);
        return;
    }

    // Look for a parent for the new node. Go down the tree (left or right) according to the key
    // Search ends when a suitable parent is found for the new node
    Node* new_element_parent = root;
    while(new_element_parent != nullptr) {
        if (new_element_parent->left == nullptr && value < new_element_parent->value) {
            new_element_parent->left = new Node(new_element_parent, value);
            return;
        }

        if (new_element_parent->right == nullptr && value >= new_element_parent->value) {
            new_element_parent->right = new Node(new_element_parent, value);
            return;
        }

        if (new_element_parent->value > value) new_element_parent = new_element_parent->left;
        else new_element_parent = new_element_parent->right;
    }
}

void BST::remove(int value) {
    Node* node = find(value);

    // If value not found in the tree - return
    if (node == nullptr) return;

    // If node has child/children we have to get its successor
    // The successor will have at most one child
    if (node->left != nullptr || node->right != nullptr) {
        Node* successor = getSuccessor(node);
        node->value = successor->value;
        node = successor;
    }

    // If node is a leaf (no children) then we have to simply disconnect it from the tree
    // If node was the root the BST becomes empty 
    if (node->left == nullptr && node->right == nullptr) {
        if (node->parent != nullptr && node->parent->left == node) node->parent->left = nullptr;
        else if (node->parent != nullptr) node->parent->right = nullptr;
        else root = nullptr;
    }

    // If node has a child then we connect the child with node's parent and delete the node
    // If node that we delete was root then the child becomes new root
    else {
        Node* child;

        if (node->left != nullptr) child = node->left;
        else child = node->right;

        if (node->parent != nullptr && node->parent->left == node) node->parent->left = child;
        else if (node->parent != nullptr) node->parent->right = child;
        else root = child;

        child->parent = node->parent;
    }

    delete node;
}