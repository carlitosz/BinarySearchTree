#include <iostream>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "BinarySearchTree.h"

// ============================================================================
// Main.
// ============================================================================
int main(void) {
    BinarySearchTree *tree = new BinarySearchTree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    cout << "Printing pre-order " << endl;
    tree->preorderPrint();

    cout << endl << endl << "Printing in-order" << endl;
    tree->inorderPrint();

    cout << endl << endl << "Printing post-order" << endl;
    tree->postorderPrint();

    delete tree;

    return 0;
}
