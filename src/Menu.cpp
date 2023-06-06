#include "Menu.h"
#include "DataStructures/BST.h"
#include "DataStructures/AVL.h"
#include "DataStructures/RedBlack.h"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu() {
    while (true) {
        clearConsole();
        displayMainMenu();

        int choice = handleMainMenuChoice();

        if (choice == 0) return;
        else if (choice == 1)  {
            cout << "bst";
            Tree<Node>* tree = new BST();
            treeMenu(tree);

        }

        else if (choice == 2) { 
            cout << "avl";
            Tree<Node>* tree = new AVL();
            treeMenu(tree);
        }

        else {
            cout << "redblack";
            Tree<Node_RB>* tree = new RedBlack();
            treeMenu(tree);
        }
    }
}

Menu::~Menu() {}

void Menu::displayMainMenu() {
    cout << "Data Structures Project - Trees\n";
    cout << "------------------------------------------------------------------------------\n";
    cout << "[ 0 ]\tShutdown program" << endl;
    cout << "[ 1 ]\tBST tree" << endl;
    cout << "[ 2 ]\tAVL tree" << endl;
    cout << "[ 3 ]\tRed Black tree" << endl << endl;
}

void Menu::displayTreeMenu() {
    cout << "-----------------------------------------------------------------------------\n";
    cout << "[ 0 ]\tExit to main menu" << endl;
    cout << "[ 1 ]\tInsert element" << endl;
    cout << "[ 2 ]\tDelete element" << endl << endl;
}

int Menu::handleMainMenuChoice() {
    string choice;

    while (true) {
        // Enter choice
        cout << ">";
        cin >> choice;

        if (choice.length() != 1) {
            clearConsole();
            displayMainMenu();   
            continue;
        }

        switch (choice[0]) {
        case '0': return 0;     // Exit
        case '1': return 1;     // BST
        case '2': return 2;     // AVL
        case '3': return 3;     // RedBlack
        
        default:
            clearConsole();
            displayMainMenu();
            break;
        }
    }
}

template <class TreeNode>
void Menu::treeMenu(Tree<TreeNode>* tree) {
    clearConsole();

    tree->print();

    displayTreeMenu();
    system("pause");
}

void Menu::clearConsole() {
    #ifdef WINDOWS  
        system("cls");
    #endif

    #ifdef LINUX
        system("clear");
    #endif
}

template class Tree<Node>;
template class Tree<Node_RB>;