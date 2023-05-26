#include "BST.h"
#include <iostream>
#include <math.h>

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

BST::BST(vector<int> elements) : BST() {
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

Node* BST::getSuccessor(Node* node) {
    // If tree empty dont look for the successor
    if (root == nullptr) return nullptr;

    // If right subtree exists then the successor will be the lowest value in it
    // Otherwise the successor will be the highset value in the left subtree
    Node* successor = minNode(node->right);

    if (successor == nullptr) {
        successor = maxNode(node->left);
    }

    return successor;
}

Node* BST::find(int value) {
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

void BST::print() {
    vector<Node*> nodes;
    indexNodes(nodes, root, 0);

    printf("-----------------------------------------------------------------------------\n");

    if(nodes.size() == 0){
        printf("puste\n");
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
                if(nodes[already_printed] != nullptr) printf("%4d", nodes[already_printed]->value);
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

void BST::indexNodes(vector<Node*> &nodes, Node* node, int node_index) {
    if(node == nullptr) return;

    // Extend size of the vector (if necessary) and assign null value
    unsigned size = pow(2, floor(log2(node_index + 1)) + 1) - 1;
    if (nodes.size() < size) {
        nodes.resize(size);

        for(int i = floor(size / 2); i < size - 1; i++) 
            nodes[i] = nullptr;
    }
    
    // Add current node to the node and start search of the left and right subtree
    nodes[node_index] = node;
    indexNodes(nodes, node->left, 2 * node_index + 1);
    indexNodes(nodes, node->right, 2 * node_index + 2);
}

Node* BST::minNode(Node* root) {
    if (root == nullptr) return nullptr;

    // Look for the lowest value in the tree (node farthest to the left)
    Node* minimum = root;
    while (minimum->left != nullptr) {
        minimum = minimum->left;
    }

    return minimum;
}

Node* BST::maxNode(Node* root) {
    if (root == nullptr) return nullptr;

    // Look for the highest value in the tree (node farthest to the right)
    Node* maximum = root;
    while(maximum->right != nullptr) {
        maximum = maximum->right;
    }

    return maximum;
}