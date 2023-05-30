#include "DataStructures/Tree.h"
#include <iostream>
#include <math.h>

template <class T>
Tree<T>::Tree() {
    root = nullptr;
}

template <class T>
T* Tree<T>::getSuccessor(T* node) {
    // If tree empty dont look for the successor
    if (root == nullptr) return nullptr;

    // If right subtree exists then the successor will be the lowest value in it
    // Otherwise the successor will be the highset value in the left subtree
    T* successor = minNode(node->right);

    if (successor == nullptr) {
        successor = maxNode(node->left);
    }

    return successor;
}

template <class T>
T* Tree<T>::find(int value) {
    T* current_node = root;

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

template <class T>
T* Tree<T>::minNode(T* root) {
    if (root == nullptr) return nullptr;

    // Look for the lowest value in the tree (node farthest to the left)
    T* minimum = root;
    while (minimum->left != nullptr) {
        minimum = minimum->left;
    }

    return minimum;
}

template <class T>
T* Tree<T>::maxNode(T* root) {
    if (root == nullptr) return nullptr;

    // Look for the highest value in the tree (node farthest to the right)
    T* maximum = root;
    while(maximum->right != nullptr) {
        maximum = maximum->right;
    }

    return maximum;
}

template <class T>
void Tree<T>::print() {
    std::vector<T*> nodes;
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

template <class T>
void Tree<T>::indexNodes(std::vector<T*> &nodes, T* node, int node_index) {
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

template class Tree<Node>;
template class Tree<Node_RB>;