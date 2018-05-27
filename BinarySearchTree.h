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
                insert(root, key);
            } else {
                root = new Node;
                root->value = key;
                root->left = NULL;
                root->right = NULL;
                root->height = 1;
            }
        }

        Node *search(int key) { return search(key, root); }
        void destroyTree() { destroyTree(root); }
        void inorderPrint() { inorderPrint(root); }
        void postorderPrint() { postorderPrint(root); }
        void preorderPrint() { preorderPrint(root); }
        void breadthFirstPrint() { breadthFirstPrint(root); }
        void remove(int key) { remove(root, key); }
        int getHeight() { return height(root); }

    private:
        Node *root;

        void destroyTree(Node *leaf);
        Node *insert(Node *leaf, int key);
        Node *search(int key, Node *leaf);
        void inorderPrint(Node *leaf);
        void postorderPrint(Node *leaf);
        void preorderPrint(Node *leaf);
        void breadthFirstPrint(Node *leaf);
        void printLevel(Node *leaf, int level);
        int getBalance(Node *leaf);
        Node *leftRotate(Node *x);
        Node *rightRotate(Node *y);
        int height(Node *leaf);
        int max(int a, int b);
        int subtreeHeight(Node *leaf);
        Node *remove(Node *leaf, int key);
        Node *minValue(Node *leaf);
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
// Right rotates the subtree rooted with y.
// ============================================================================
Node *BinarySearchTree::rightRotate(Node *y) {
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// ============================================================================
// Returns the max of a or b.
// ============================================================================
int BinarySearchTree::max(int a, int b) {
    return (a > b) ? a : b;
}

// ============================================================================
// Left rotates the subtree rooted with x.
// ============================================================================
Node *BinarySearchTree::leftRotate(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
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
        postorderPrint(leaf->left);
        postorderPrint(leaf->right);
        cout << leaf->value << ",";
    }
}

// ============================================================================
// Prints "breadth first" style.
// ============================================================================
void BinarySearchTree::breadthFirstPrint(Node *root) {
    int h = root->height + 1;
    for (int i = 0; i < h; ++i) {
        printLevel(root, i);
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
    return leaf->height;
}

// ============================================================================
// Height of each subtree.
// ============================================================================
int BinarySearchTree::subtreeHeight(Node* leaf) {
    if (leaf == NULL)
        return 0;
    else {
        int lheight = subtreeHeight(leaf->left);
        int rheight = subtreeHeight(leaf->right);
 
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}

// ============================================================================
// Prints "pre order" style.
// ============================================================================
void BinarySearchTree::preorderPrint(Node *leaf) {
    if (leaf != NULL) {
        cout << leaf->value << ",";
        preorderPrint(leaf->left);
        preorderPrint(leaf->right);
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
// Returns the balance at the given leaf.
// ============================================================================
int BinarySearchTree::getBalance(Node *leaf) {
    if (leaf == NULL) return 0;

    return height(leaf->left) - height(leaf->right);
}

// ============================================================================
// Inserts into the tree.
// ============================================================================
Node *BinarySearchTree::insert(Node *leaf, int key) {
    if (leaf == NULL) {
        leaf = new Node;
        leaf->value = key;
        leaf->left = NULL;
        leaf->right = NULL;
        leaf->height = 1;

        return leaf;
    }

    if (key < leaf->value) {
        leaf->left = insert(leaf->left, key);
    } else if (key > leaf->value) {
        leaf->right = insert(leaf->right, key);
    } else {
        return leaf;
    }

    leaf->height = 1 + max(height(leaf->left), height(leaf->right));
    int balance = getBalance(leaf);

    if (balance > 1 && key < leaf->left->value) {
        return rightRotate(leaf);
    }

    if (balance < -1 && key > leaf->right->value) {
        return leftRotate(leaf);        
    }

    if (balance > 1 && key > leaf->left->value) {
        leaf->left = leftRotate(leaf->left);
        return rightRotate(leaf);
    }

    if (balance < -1 && key < leaf->right->value) {
        leaf->right = rightRotate(leaf->right);
        return leftRotate(leaf);        
    }

    return leaf;
}

// ============================================================================
// Removes a given key from the tree.
// ============================================================================
Node *BinarySearchTree::remove(Node *leaf, int key) {
    if (leaf == NULL) {
        return leaf;
    }

    if (key < leaf->value) {
        leaf->left = remove(leaf->left, key);
    } else if(key > leaf->value) {
        leaf->right = remove(leaf->right, key);
    } else {
        if (leaf->left == NULL || leaf->right == NULL) {
            Node *temp = leaf->left ? leaf->left : leaf->right;

            if (temp == NULL) {
                temp = leaf;
                leaf = NULL;
            } else {
                *leaf = *temp;
            }

            delete temp;
        } else {
            Node *temp = minValue(leaf->right);
            leaf->value = temp->value;
            leaf->right = remove(leaf->right, temp->value);
        }
    }

    if (leaf == NULL) return leaf;
    leaf->height = 1 + max(height(leaf->left), height(leaf->right));
    int balance = getBalance(leaf);

    if (balance > 1 && getBalance(leaf->left) >= 0) {
        return rightRotate(leaf);
    }

    if (balance > 1 && getBalance(leaf->left) < 0) {
        leaf->left = leftRotate(leaf->left);
        return rightRotate(leaf);        
    }

    if (balance < -1 && getBalance(leaf->right) <= 0) {
        return leftRotate(leaf);
    }

    if (balance < -1 && getBalance(leaf->right) > 0) {
        leaf->right = rightRotate(leaf->right);
        return leftRotate(leaf);
    }

    return leaf;
}

// ============================================================================
// Returns the node with the minimum value.
// ============================================================================
Node *BinarySearchTree::minValue(Node* leaf) {
    Node *current = leaf;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

#endif /* BINARY_SEARCH_TREE_H */
