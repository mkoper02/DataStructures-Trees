#include <iostream>
#include "DataStructures/BST.h"
#include "DataStructures/AVL.h"

using namespace std;

int main() {
    vector<int> arr, arr1;
    arr.insert(arr.end(), {12, 5, 11, 9, 7, 2, 3});
    arr1.insert(arr1.end(), {11, 12, 5, 7, 3, 2});

    Tree* avl = new AVL(arr);
    // Tree* bst = new BST(arr1);

    // cout << "AVL:" << endl;
    avl->print();
    avl->remove(9);
    avl->remove(7);
    avl->print();

    // cout << "BST:" << endl;
    // bst->print();
    // bst->remove(7);
    // bst->print();

    system("pause");
}