#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cmath>
using namespace std;

#include "Node.h"

class BinarySearchTree {
    public:
        BinarySearchTree();
        ~BinarySearchTree();

        void insert(int key) {
            if (root != NULL) {
                insert(key, root);
            } else {
                root = new Node;
                root->value = key;
                root->left = NULL;
                root->right = NULL;
            }
        }

        Node *search(int key) { return search(key, root); }
        void destroyTree() { destroyTree(root); }
        void inorderPrint() { inorderPrint(root); }
        void postorderPrint() { postorderPrint(root); }
        void preorderPrint() { preorderPrint(root); }
        void breadthFirstPrint() { breadthFirstPrint(root); }
        int height() { return height(root); }
        bool isBalanced() { return isBalanced(root); }

    private:
        Node *root;

        void destroyTree(Node *leaf);
        void insert(int key, Node *leaf);
        Node *search(int key, Node *leaf);
        void inorderPrint(Node *leaf);
        void postorderPrint(Node *leaf);
        void preorderPrint(Node *leaf);
        void breadthFirstPrint(Node *leaf);
        int height(Node *leaf);
        void printLevel(Node *leaf, int level);
        bool isBalanced(Node *leaf);
};


// ============================================================================
// Consturctor.
// ============================================================================
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

// ============================================================================
// Destructor.
// ============================================================================
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

// ============================================================================
// Checks if the tree is balanced.
// ============================================================================
bool BinarySearchTree::isBalanced(Node *leaf) {
    if (leaf == NULL) return true;

    int left = height(leaf->left);
    int right = height(leaf->right);

    if (abs(left - right) <= 1
        && isBalanced(leaf->left)
        && isBalanced(leaf->right)) {
        return true;
    }

    return false;
}

// ============================================================================
// Destroy.
// ============================================================================
void BinarySearchTree::destroyTree(Node *leaf) {
    if (leaf != NULL) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

// ============================================================================
// Prints "in order" style.
// ============================================================================
void BinarySearchTree::inorderPrint(Node *leaf) {
    if (leaf != NULL) {
        inorderPrint(leaf->left);
        cout << leaf->value << ",";
        inorderPrint(leaf->right);        
    }
}

// ============================================================================
// Prints "post order" style.
// ============================================================================
void BinarySearchTree::postorderPrint(Node *leaf) {
    if (leaf != NULL) {
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
        cout << leaf->value << ",";
    }
}

// ============================================================================
// Prints "breadth first" style.
// ============================================================================
void BinarySearchTree::breadthFirstPrint(Node *leaf) {
    int h = height(leaf) + 1;
    for (int i = 0; i < h; ++i) {
        printLevel(leaf, i);
    }
}

// ============================================================================
// Prints nodes at a given level.
// ============================================================================
void BinarySearchTree::printLevel(Node *leaf, int level) {
    if (leaf == NULL) {
        return;
    }

    if (level == 1) {
        cout << leaf->value << ",";
    } else if (level > 1) {
        printLevel(leaf->left, level - 1);
        printLevel(leaf->right, level - 1);
    }
}

// ============================================================================
// Returns the height of the tree.
// ============================================================================
int BinarySearchTree::height(Node *leaf) {
    if (leaf == NULL) return 0;
    else {
        int lheight = height(leaf->left);
        int rheight = height(leaf->right);

        if (lheight > rheight) {
            return lheight + 1;
        } else {
            return rheight + 1;
        }
    }
}

// ============================================================================
// Prints "pre order" style.
// ============================================================================
void BinarySearchTree::preorderPrint(Node *leaf) {
    if (leaf != NULL) {
        cout << leaf->value << ",";
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
    }
}

// ============================================================================
// Searches the tree for a value.
// ============================================================================
Node *BinarySearchTree::search(int key, Node *leaf) {
    if (leaf != NULL) {
        if (key == leaf->value) {
            return leaf;
        }
        if (key < leaf->value) {
            return search(key, leaf->left);
        } else {
            return search(key, leaf->right); 
        }
    } else {
        return NULL;
    }
}

// ============================================================================
// Inserts into the tree.
// ============================================================================
void BinarySearchTree::insert(int key, Node *leaf) {
    if (key < leaf->value) {
        if (leaf->left != NULL) {
            insert(key, leaf->left);
        } else {
            leaf->left = new Node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if (key >= leaf->value) {
        if (leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
            leaf->right = new Node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}

#endif /* BINARY_SEARCH_TREE_H */
