#ifndef RED_BLACK_TREE_RB_TREE_H
#define RED_BLACK_TREE_RB_TREE_H

#include "RBNode.h"

class RBTree {
private:
    RBNode *const nil;
    RBNode *head;
public:
    RBTree();

    RBNode *search(int elem);

    void insert(int elem);

    void insert(RBNode *newNode);

    void insertFixup(RBNode *node);

    void leftRotate(RBNode *node);

    void rightRotate(RBNode *node);

    void remove(int elem);

    void printTree(RBNode *root, int space) const;

    void printTree() const;
};


#endif //RED_BLACK_TREE_RB_TREE_H
