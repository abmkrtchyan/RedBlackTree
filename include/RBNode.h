#ifndef RED_BLACK_TREE_RB_NODE_H
#define RED_BLACK_TREE_RB_NODE_H

#include <iostream>
#include <Node.h>

enum Color
{
    RED = true,
    BLACK = false
};

template <class T>
class RBNode : public Node<T>
{
public:
    RBNode* parent;
    RBNode* left;
    RBNode* right;
    Color color;


    explicit RBNode(
        const T& data,
        RBNode* parent = nullptr,
        RBNode* left = nullptr,
        RBNode* right = nullptr,
        const Color& color = RED
    ) : Node<T>(data), parent(parent), left(left), right(right), color(color)
    {
    }

    void print() const
    {
        std::cout << this->data;
        this->color == RED ? std::cout << "(RED)" : std::cout << "(BLACK)";
        std::cout << "\n";
    }

    ~RBNode() = default;
};

#endif //RED_BLACK_TREE_RB_NODE_H
