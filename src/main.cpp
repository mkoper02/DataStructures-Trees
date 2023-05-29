#include <iostream>
#include "DataStructures/BST.h"
#include "DataStructures/AVL.h"

using namespace std;

int main() {
    vector<int> arr;
    arr.insert(arr.end(), {12, 5, 7, 11, 9});
    arr.insert(arr.end(), {7, 2, 11, 3, 4});

    Tree* avl = new AVL(arr);
    Tree* bst = new BST(arr);

    cout << "AVL:" << endl;
    avl->print();
    cout << "BST:" << endl;
    bst->print();

    system("pause");
}