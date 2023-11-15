#ifndef RED_BLACK_TREE_RB_NODE_H
#define RED_BLACK_TREE_RB_NODE_H

#include <iostream>

enum Color {
    RED = true, BLACK = false
};

class RBNode {
public:
    RBNode *left;
    RBNode *right;
    RBNode *parent;
    int data;
    Color color;

    RBNode(int data,
           Color color = RED,
           RBNode *left = nullptr,
           RBNode *right = nullptr,
           RBNode *parent = nullptr)
            : data(data),
              left(left),
              right(right),
              parent(parent),
              color(color) {};

    void print() const {
        std::cout << this->data;
        this->color == RED ? std::cout << "(RED)" : std::cout << "(BLACK)";
        std::cout << "\n";
    }
};


#endif //RED_BLACK_TREE_RB_NODE_H
