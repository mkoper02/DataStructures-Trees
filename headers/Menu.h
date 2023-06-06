#include "DataStructures/Tree.h"

class Menu {
private:
    // Display menu to choose tree
    void displayMainMenu();

    // Display tree to choose operations
    void displayTreeMenu();

    // Handle user input
    int handleMainMenuChoice();
    int handleTreeChoice();

    // Enter correct value and format
    int enterValue();

    template <class TreeNode>
    void treeMenu(Tree<TreeNode>* tree);

    void clearConsole();

public:
    // Default constructor
    Menu();

    // Destructor
    ~Menu();
};