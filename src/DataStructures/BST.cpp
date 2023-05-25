#include "BST.h"

Node::Node() {
    value = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Node::Node(Node *parent, int value) {
    this->parent = parent;
    this->value = value;
    left = nullptr;
    right = nullptr;
}

BST::BST() {
    root = nullptr;
}

BST::BST(vector<int> elements) {

}

BST::~BST() {
    
}

void BST::add(int value) {
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

}

Node* BST::find(int value) {
    Node* current_node = root;

    while (current_node != nullptr) {
        if (current_node->value == value) {
            return current_node;
        }

        if (current_node->value > value) current_node = current_node->left;
        else current_node = current_node->right;
    }

    return nullptr;
}

void BST::print() {

}