#include <iostream>
#include "DataStructures/BST.h"
#include "DataStructures/AVL.h"

using namespace std;

int main() {
    // vector<int> arr;
    // arr.insert(arr.end(), {12, 5, 7, 11, 9});

    // BST bst(arr);
    // bst.print();

    // bst.remove(11);
    // bst.print();

    // bst.remove(12);
    // bst.print();

    AVL avl;

    avl.add(12);
    avl.add(7);
    avl.add(5);
    avl.add(4);
    avl.add(3);
    avl.add(2);

    avl.print();

    avl.add(15);
    avl.add(16);
    avl.add(17);
    avl.add(18);

    avl.print();

    system("pause");
}