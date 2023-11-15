#include <iostream>
#include "RBTree.h"

RBTree::RBTree() : nil(new RBNode(0, BLACK)), head(this->nil) {}

RBNode *RBTree::search(int elem) {
    RBNode *current = this->head;
    while (current != this->nil) {
        if (current->data == elem) return current;
        current = (elem < current->data) ? current->left : current->right;
    }
    return this->nil;
}


void RBTree::remove(int elem) {
    return;
}

void RBTree::printTree(RBNode *root, int space) const {
    if (root == nullptr)
        return;
    space++;
    printTree(root->right, space);
    std::cout << std::endl;
    for (int i = 1; i < space; i++) {
        std::cout << "\t\t";
    }
    root->print();
    printTree(root->left, space);
}

void RBTree::printTree() const {
    printTree(this->head, 0);
}

void RBTree::insert(int elem) {
    insert(new RBNode(elem));
}

void RBTree::insert(RBNode *newNode) {
    RBNode *parent = this->nil;
    RBNode *current = this->head;
    while (current != this->nil) {
        parent = current;
        if (newNode->data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    newNode->parent = parent;
    if (parent == this->nil) {
        this->head = newNode;
    } else if (newNode->data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    newNode->left = this->nil;
    newNode->right = this->nil;
    newNode->color = RED;
    insertFixup(newNode);
}


void RBTree::insertFixup(RBNode *x) {
    while (x->parent->color == RED) {
        if (x->parent == x->parent->parent->left) {
            auto y = x->parent->parent->right;
            if (y->color == RED) {
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    leftRotate(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rightRotate(x->parent->parent);
            }
        } else {
            // սիմետրիկ լրացնել, երբ z.p-ը աջ ժառանգ է
        }
    }
    this->head->color = BLACK;
}

void RBTree::leftRotate(RBNode *A) {
    RBNode *B = A->right;
    A->right = B->left;

    if (B->left != this->nil) {
        B->left->parent = A;
    }
    B->parent = A->parent;
    if (A->parent == this->nil) {
        this->head = B;
    } else if (A == A->parent->left) {
        A->parent->left = B;
    } else {
        A->parent->right = B;
    }
    B->left = A;
    A->parent = B;
}


void RBTree::rightRotate(RBNode *node) {
    //write code
}
