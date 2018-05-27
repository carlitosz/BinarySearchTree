#include <iostream>
#include <string>
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

    // tree->insert(10);
    // tree->insert(6);
    // tree->insert(14);
    // tree->insert(5);
    // tree->insert(8);
    // tree->insert(11);
    // tree->insert(18);

    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);

    cout << "Printing pre-order " << endl;
    tree->preorderPrint();

    cout << endl << endl << "Printing in-order" << endl;
    tree->inorderPrint();

    cout << endl << endl << "Printing post-order" << endl;
    tree->postorderPrint();

    cout << endl << endl << "Printing breadth-first" << endl;
    tree->breadthFirstPrint();

    // Print tree stats
    string isBalanced;
    isBalanced = (tree->isBalanced() == true) ? "" : " not";
    cout << endl << endl << "Tree is" << isBalanced << " balanced." << endl;
    cout << "Height of the tree is " << tree->height() << endl << endl;

    delete tree;

    return 0;
}
