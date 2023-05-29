#include "DataStructures/AVL.h"

AVL::AVL() : Tree() {}

AVL::AVL(std::vector<int> elements) : AVL() {
    if (elements.empty()) return;

    for (auto element : elements) {
        add(element);
    }
}

AVL::~AVL() {

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
    if (main_node == nullptr || new_node == nullptr) return;

    int balance_factor = getBalanceFactor(main_node);

    // Left rotate
    if (balance_factor < -1 && new_node->value > main_node->right->value) {
        leftRotation(main_node);
    }

    // Left Right rotate
    else if (balance_factor > 1 && new_node->value > main_node->left->value) {
        leftRightRotation(main_node);
    }

    // Right rotate
    else if (balance_factor > 1 && new_node->value < main_node->left->value) {
        rightRotation(main_node);
    }

    // Right Left rotate
    else if (balance_factor < -1 && new_node->value < main_node->right->value) {
        rightLeftRotation(main_node);
    }
}

void AVL::leftRotation(Node* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->right == nullptr) return;

    Node* new_right_root = node->right;

    //Rotation
    node->right = new_right_root->left;
    if (node->right != nullptr) {
        node->right->parent = node;
    }

    // Copy data
    new_right_root->left = node;
    new_right_root->parent = node->parent;
    node->parent = new_right_root;

    // If given node was root we have to assign it again
    // Else we have to assign new child 
    if (new_right_root->parent == nullptr) {
        root = new_right_root;
    }
    else {
        new_right_root->parent->left = new_right_root;
    }
}

void AVL::rightRotation(Node* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->left == nullptr) return;

    Node* new_left_root = node->left;

    // Rotation
    node->left = new_left_root->right;
    if (node->left != nullptr) {
        node->left->parent = node; 
    }

    // Copy data 
    new_left_root->right = node;
    new_left_root->parent = node->parent;
    node->parent = new_left_root;

    // If given node was root we have to assign it again
    // Else we have to assign new child 
    if (new_left_root->parent == nullptr) {
        root = new_left_root;
    }
    else {
        new_left_root->parent->right = new_left_root;
    }
}

void AVL::leftRightRotation(Node* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->left == nullptr) return;

    Node* new_left_node = node->left->right;

    // Rotation
    node->left->right = new_left_node->left;
    if (node->left->right != nullptr) {
        node->left->right->parent = node->left;
    }

    // Copy data
    new_left_node->left = node->left;
    node->left->parent = new_left_node;
    node->left = new_left_node;
    new_left_node->parent = node;

    rightRotation(node);
}

void AVL::rightLeftRotation(Node* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->right == nullptr) return;

    Node* new_right_node = node->right->left;

    // Rotation
    node->right->left = new_right_node->right;
    if (node->right->left != nullptr) {
        node->right->left->parent = node->right;
    }

    // Copy data
    new_right_node->right = node->right;
    node->right->parent = new_right_node;
    node->right = new_right_node;
    new_right_node->parent = node;

    leftRotation(node);
}