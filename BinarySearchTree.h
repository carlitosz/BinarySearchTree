#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

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

    private:
        Node *root;

        void destroyTree(Node *leaf);
        void insert(int key, Node *leaf);
        Node *search(int key, Node *leaf);
        void inorderPrint(Node *leaf);
        void postorderPrint(Node *leaf);
        void preorderPrint(Node *leaf);
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
