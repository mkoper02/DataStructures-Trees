#include <iostream>
#include "DataStructures/BST.h"
#include "DataStructures/AVL.h"

using namespace std;

int main() {
    vector<int> arr;
    // arr.insert(arr.end(), {12, 5, 7, 11, 9});
    arr.insert(arr.end(), {7, 2, 11, 3, 4});

    AVL avl(arr);

    avl.print();

    system("pause");
}