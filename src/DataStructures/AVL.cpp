#include "DataStructures/AVL.h"
#include <iostream>

AVL::AVL() {
    root = nullptr;
}

AVL::~AVL() {

}

Node *AVL::find(int value) {
    Node* current_node = root;

    // Start from the root and look for the node with the given key
    // If the key is lesser than the current element start searching in the right subtree
    // If the key is greater than the current element start searching in the left subtree
    while (current_node != nullptr) {
        if (current_node->value == value) {
            return current_node;
        }

        if (current_node->value > value) current_node = current_node->left;
        else current_node = current_node->right;
    }

    return nullptr;
}

int AVL::getHeight(Node *node) {
    // If tree is empty
    if (node == nullptr) return -1;

    // Check height of the subtrees
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    // Choose larger value
    if (left_height > right_height) return left_height + 1;
    else return right_height + 1;
}

int AVL::getBalanceFactor(Node *node) { 
    if (node == nullptr) return -1;
    return getHeight(node->left) - getHeight(node->right);
}

void AVL::add(int value) {
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
            balanceTree(new_element_parent->parent, new_element_parent->left);
            return;
        }

        if (new_element_parent->right == nullptr && value >= new_element_parent->value) {
            new_element_parent->right = new Node(new_element_parent, value);
            balanceTree(new_element_parent->parent, new_element_parent->right);
            return;
        }

        if (new_element_parent->value > value) new_element_parent = new_element_parent->left;
        else new_element_parent = new_element_parent->right;
    }
}

void AVL::balanceTree(Node* main_node, Node* new_node) {
    if (main_node == nullptr) return;

    int balance_factor = getBalanceFactor(main_node);

    // Left rotate
    if (balance_factor < -1 && new_node->value > main_node->right->value) {

    }

    // Left Right rotate
    if (balance_factor > 1 && new_node->value > main_node->left->value) {

    }

    // Right rotate
    if (balance_factor > 1 && new_node->value < main_node->left->value) {

    }

    // Right Left rotate
    if (balance_factor < -1 && new_node->value < main_node->right->value) {
        
    }
}