#define WINDOWS
#ifdef WINDOWS 
    #include <windows.h>
#endif

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
            Tree<Node>* tree = new BST();
            treeMenu(tree);
        }

        else if (choice == 2) { 
            Tree<Node>* tree = new AVL();
            treeMenu(tree);
        }

        else {
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

int Menu::handleTreeChoice() {
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
        case '0': return 0;     // exit
        case '1': return 1;     // add
        case '2': return 2;     // remove
        
        default:
            cout << "Invalid input!\n";
            break;
        }
    }
}

template <class TreeNode>
void Menu::treeMenu(Tree<TreeNode>* tree) {
    bool is_running = true;
    int input;

    while (true) {
        clearConsole();

        cout << "CURRENT STATE OF THE TREE:\n";
        tree->print();

        displayTreeMenu();

        int choice = handleTreeChoice();
        if (choice != 0) input = enterValue();
        if (input == -9999) continue;

        switch (choice) {
            case 0: delete tree; return;
            case 1: 
                tree->add(input);
                break;
            case 2:
                tree->remove(input);
                break;
        }
    }

}

int Menu::enterValue() {
    string value;

    cout << "\nEnter value: ";
    cin >> value;
    cout << value.length() << endl;
    for (int i = 0; i < value.length(); i++) {
        cout << value[i] << "\t";
        if (isdigit(value[i]) == false) {
            return -9999;
        }
    }

    return stoi(value);
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