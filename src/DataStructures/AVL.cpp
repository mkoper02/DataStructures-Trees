#include "DataStructures/AVL.h"

AVL::AVL() {
    root = nullptr;
}

AVL::~AVL() {

}

int AVL::getHeight(Node *node) {
    // If tree is empty
    if (node == nullptr) return -1;

    // Check height of the subtrees
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    // choose larger value
    if (left_height > right_height) return left_height + 1;
    else return right_height + 1;
}
