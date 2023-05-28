#include <iostream>
#include "DataStructures/BST.h"

using namespace std;

int main() {
    vector<int> arr;
    arr.insert(arr.end(), {12, 5, 7, 11, 9});

    BST bst(arr);
    bst.print();

    bst.remove(11);
    bst.print();

    bst.remove(12);
    bst.print();

    system("pause");
}