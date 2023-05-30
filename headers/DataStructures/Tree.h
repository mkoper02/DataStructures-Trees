#pragma once

#include "Node.h"
#include <vector>

// Class representing Binary Tree
template <class T>   // T - Node/Node_RB
class Tree {
protected:
    T* root;         // root of the tree
public:
    // Constructor
    Tree();

    // Add element with given value to the tree
    virtual void add(int value) = 0;

    // Remove element with given value from the tree
    virtual void remove(int value) = 0;

    // Get successor in place of the removed node
    T* getSuccessor(T* node);

    // Search for element with given value in the tree and return its address
    T* find(int value);

    // Search for the lwoest value in the tree and return its address
    T* minNode(T* root);

    // Search for the largest value in the tree and return its adress 
    T* maxNode(T* root);

    // Root getter
    T* getRoot() { return root; }

    // Print tree
    void print();

    // Creates array with all nodes from the tree
    // nodes - array to store nodes
    // node - address of the node where function should start
    // node_index - index of the node 
    void indexNodes(std::vector<T*> &nodes, T* node, int node_index);
};