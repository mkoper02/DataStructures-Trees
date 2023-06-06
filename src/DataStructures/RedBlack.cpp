#include "DataStructures/RedBlack.h"
#include <iostream>
#include <math.h>

RedBlack::RedBlack() : Tree() {}

RedBlack::RedBlack(std::vector<int> elements) : RedBlack() {
    if (elements.empty()) return;

    // Add data to the tree
    for (auto element : elements) {
        add(element);
    }
}

RedBlack::~RedBlack() {
    while (root != nullptr) {
        remove(root->value);
    }
}

void RedBlack::add(int value) {
    // Dont allow nodes with the same value
    if (find(value) != nullptr) return;

    // If tree is emptpy new value becomes root 
    if (root == nullptr) {
        root = new Node_RB(nullptr, value);
        root->colour = BLACK;   // root always black
        return;
    }

    // Look for a parent for the new node. Go down the tree (left or right) according to the key
    // Search ends when a suitable parent is found for the new node
    Node_RB* new_element_parent = root;
    while(new_element_parent != nullptr) {
        if (new_element_parent->left == nullptr && value < new_element_parent->value) {
            new_element_parent->left = new Node_RB(new_element_parent, value);
            checkColour(new_element_parent->left);
            return;
        }

        if (new_element_parent->right == nullptr && value >= new_element_parent->value) {
            new_element_parent->right = new Node_RB(new_element_parent, value);
            checkColour(new_element_parent->right);
            return;
        }

        if (new_element_parent->value > value) new_element_parent = new_element_parent->left;
        else new_element_parent = new_element_parent->right;
    }
}

void RedBlack::remove(int value) {
    Node_RB* node = find(value);

    // If value not found in the tree - return
    if (node == nullptr) return;

    // If node has child/children we have to get its successor
    // The successor will have at most one child
    if (node->left != nullptr || node->right != nullptr) {
        Node_RB* successor = getSuccessor(node);
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
        Node_RB* child;

        if (node->left != nullptr) child = node->left;
        else child = node->right;

        if (node->parent != nullptr && node->parent->left == node) node->parent->left = child;
        else if (node->parent != nullptr) node->parent->right = child;
        else root = child;

        child->parent = node->parent;
    }

    if (node->parent != nullptr) checkColour(node->parent);
    delete node;
}

void RedBlack::checkColour(Node_RB* node) {
    if (node == root && root != nullptr) {
        root->colour = BLACK;
        return;
    }

    // Dont allow two red nodes one after the other - fix the three
    if (node->colour == RED && node->parent->colour == RED) {
        correctTree(node);
    }

    if (node == root) {
        root->colour = BLACK;
        return;
    }

    // Check next nodes
    checkColour(node->parent);
}

// Correct any violations of the Red Black tree
void RedBlack::correctTree(Node_RB* node) {
    if (node->parent->parent == nullptr) return;

    // Aunt is node->parent->parent->right
    if (isLeftChild(node->parent)) {
        // If aunt is black then rotate (colour black or nullptr)
        if (node->parent->parent->right == nullptr || node->parent->parent->right->colour == BLACK) {
            return rotate(node);
        }

        // If aunt is red then switch colors
        if (node->parent->parent->right != nullptr) {
            node->parent->parent->right->colour = BLACK;
        }
        node->parent->colour = BLACK;
        node->parent->parent->colour = RED;
    }

    // Aunt is node->parent->parent->left
    else {
        // If aunt is black then rotate (colour black or nullptr)
        if (node->parent->parent->left == nullptr || node->parent->parent->left->colour == BLACK) {
            return rotate(node);
        }

        // If aunt is red then switch colors
        if (node->parent->parent->left != nullptr) {
            node->parent->parent->left->colour = BLACK;
        }
        node->parent->colour = BLACK;
        node->parent->parent->colour = RED;
    }
}

bool RedBlack::isLeftChild(Node_RB* node) {
    if (node->parent == nullptr) return false;

    if (node->parent->left == node) return true;
    return false;
}

void RedBlack::rotate(Node_RB* node) {
    if (isLeftChild(node)) {
        if (isLeftChild(node->parent)) {
            rightRotation(node->parent->parent);

            // Fix colours
            node->colour = RED;
            node->parent->colour = BLACK;
            if (node->parent->right != nullptr) node->parent->right->colour = RED;
        }

        else {
            rightLeftRotation(node->parent->parent);
            
            // Fix colours
            node->colour = BLACK;
            node->right->colour = RED;
            node->left->colour = RED;
        }
    }
    
    else {
        if (!isLeftChild(node->parent)) {
            leftRotation(node->parent->parent);

            // Fix colours
            node->colour = RED;
            node->parent->colour = BLACK;
            if (node->parent->left != nullptr) node->parent->left->colour = RED;
        }

        else {
            leftRightRotation(node->parent->parent);

            // Fix colours
            node->colour = BLACK;
            node->right->colour = RED;
            node->left->colour = RED;
        }
    }
}

void RedBlack::leftRotation(Node_RB* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->right == nullptr) return;

    Node_RB* new_right_root = node->right;

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
        return;
    }

    if (new_right_root->value < new_right_root->parent->value) new_right_root->parent->left = new_right_root;
    else new_right_root->parent->right = new_right_root;
}

void RedBlack::rightRotation(Node_RB* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->left == nullptr) return;

    Node_RB* new_left_root = node->left;

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
        return;
    }

    if (new_left_root->value < new_left_root->parent->value) new_left_root->parent->left = new_left_root;
    else new_left_root->parent->right = new_left_root;
}

void RedBlack::leftRightRotation(Node_RB* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->left == nullptr) return;

    Node_RB* new_left_node = node->left->right;

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

void RedBlack::rightLeftRotation(Node_RB* node) {
    // If node or node's left child doesnt exist - dont rotate
    if (node == nullptr || node->right == nullptr) return;

    Node_RB* new_right_node = node->right->left;

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

void RedBlack::print() {
    std::vector<Node_RB*> nodes;
    indexNodes(nodes, root, 0);

    printf("-----------------------------------------------------------------------------\n");

    if(nodes.size() == 0){
        printf("Empty\n");
        return;
    }

    unsigned height = 2*floor(log2(nodes.size()))+1;
    unsigned width = 2*pow(2, floor(log2(nodes.size()))) - 1;
    
    int p = width+1;
    int already_printed = 0;

    for(int y = 1; y <= height; y++){

        if(y%2 == 0) {
            printf("\n\n");
            continue;
        }

        for(int x = 1; x <= width; x++){

            
            if(x%p == p/2) {
                if(nodes[already_printed] != nullptr) {
                    printf("%4d", nodes[already_printed]->value);
                    if (nodes[already_printed]->colour == RED) printf("R");
                }
                else printf("    ");
                already_printed++;
            }
            else printf("    ");

            if(already_printed == nodes.size()){
                printf("\n\n");
                return;
            }

        }
        if(y%2 == 1) p /= 2;
    }
}