#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "BinarySearchTree.h"

void print(BinarySearchTree *);

// ============================================================================
// Main.
// ============================================================================
int main(void) {
    BinarySearchTree *tree = new BinarySearchTree();

    cout << "======== Printing tree ===============" << endl;
    // Insert into tree
    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);
    print(tree);
    cout << "======================================" << endl << endl;

    cout << "======== Removing root (10) ==========" << endl;
    tree->remove(10);
    print(tree);
    cout << "======================================" << endl << endl;

    cout << "======== Removing leaf (8) ===========" << endl;
    tree->remove(8);
    print(tree);
    cout << "======================================" << endl << endl;

    cout << "======== Inserting (23) ==============" << endl;
    tree->insert(23);
    print(tree);
    cout << "======================================" << endl << endl;

    cout << "===== Deleting all minus root ========" << endl;
    tree->remove(23);
    tree->remove(5);
    tree->remove(14);
    tree->remove(18);
    tree->remove(6);
    print(tree);
    cout << "======================================" << endl << endl;

    delete tree;

    return 0;
}

void print(BinarySearchTree *tree) {
    cout << "Printing pre-order " << endl;
    tree->preorderPrint();

    cout << endl << endl << "Printing in-order" << endl;
    tree->inorderPrint();

    cout << endl << endl << "Printing post-order" << endl;
    tree->postorderPrint();

    cout << endl << endl << "Printing breadth-first" << endl;
    tree->breadthFirstPrint();

    cout << endl << endl << "Height of the tree is: " << tree->getHeight() << endl;
}