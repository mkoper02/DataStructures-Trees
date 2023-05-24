#include "BST.h"

Node::Node() {
    value = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Node::Node(int value, Node *parent) {
    this->value;
    this->parent = parent;
    left = nullptr;
    right = nullptr;
}

BST::BST() {
    root = nullptr;
}

BST::BST(vector<int> elements)
{
}

BST::~BST() {
    
}

void BST::add(int value) {

}

void BST::remove(int value) {
}

Node *BST::find(int value) {
    return nullptr;
}

void BST::print() {

}