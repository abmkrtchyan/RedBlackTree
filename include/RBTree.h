#ifndef RED_BLACK_TREE_RB_TREE_H
#define RED_BLACK_TREE_RB_TREE_H

#include "RBNode.h"
#include "BinarySearchTree.h"

template <class T = int>
class RBTree : public AbstractBinaryTree<T>
{
public:
    RBTree();

    Node<T>* search(const T& elem) override;

    void insert(const T& elem) override;

    void remove(const T& elem) override;

    void rbInsert(RBNode<T>* newNode);

    void insertFixup(RBNode<T>*);

    void leftRotate(RBNode<T>*);

    void rightRotate(RBNode<T>*);

    void printTree();

    void printTree(RBNode<T>* root, int space);

    ~RBTree() override
    {
        delete head;
    }

private:
    RBNode<T>* const nil;

    RBNode<T>* head;
};


#endif //RED_BLACK_TREE_RB_TREE_H

template <class T>
RBTree<T>::RBTree() : nil(new RBNode<T>(T(), nullptr, nullptr, nullptr, BLACK))
{
    this->head = this->nil;
}

template <class T>
Node<T>* RBTree<T>::search(const T& elem)
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (**current == elem)
        {
            return current;
        }
        current = (elem < **current) ? current->left : current->right;
    }
    return nullptr;
}

template <class T>
void RBTree<T>::remove(const T& elem)
{
}

template <class T>
void RBTree<T>::insert(const T& elem)
{
    rbInsert(new RBNode<T>(elem));
}

template <class T>
void RBTree<T>::rbInsert(RBNode<T>* newNode)
{
    RBNode<T>* parent = this->nil;
    auto current = this->head;
    while (current != this->nil)
    {
        parent = current;
        if (newNode->data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    newNode->parent = parent;
    if (parent == this->nil)
    {
        this->head = newNode;
    }
    else if (newNode->data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    newNode->left = this->nil;
    newNode->right = this->nil;
    newNode->color = RED;
    insertFixup(newNode);
}

template <class T>
void RBTree<T>::insertFixup(RBNode<T>* node)
{
    while (node->parent->color == RED)
    {
        if (node->parent == node->parent->parent->left)
        {
            auto y = node->parent->parent->right;
            if (y->color == RED)
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rightRotate(node->parent->parent);
            }
        }
        else
        {
            auto y = node->parent->parent->left;
            if (y->color == RED)
            {
                node->parent->color = BLACK;
                y->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                leftRotate(node->parent->parent);
            }
        }
    }
    this->head->color = BLACK;
}


template <class T>
void RBTree<T>::leftRotate(RBNode<T>* A)
{
    auto B = A->right;
    A->right = B->left;

    if (B->left != this->nil)
    {
        B->left->parent = A;
    }
    B->parent = A->parent;
    if (A->parent == this->nil)
    {
        this->head = B;
    }
    else if (A == A->parent->left)
    {
        A->parent->left = B;
    }
    else
    {
        A->parent->right = B;
    }
    B->left = A;
    A->parent = B;
}

template <class T>
void RBTree<T>::rightRotate(RBNode<T>* A)
{
    auto B = A->left;
    A->left = B->right;

    if (B->right != this->nil)
    {
        B->right->parent = A;
    }
    B->parent = A->parent;
    if (A->parent == this->nil)
    {
        this->head = B;
    }
    else if (A == A->parent->right)
    {
        A->parent->right = B;
    }
    else
    {
        A->parent->left = B;
    }
    B->right = A;
    A->parent = B;
}

template <class T>
void RBTree<T>::printTree(RBNode<T>* root, int space)
{
    if (root == this->nil)
        return;
    space += 6;
    printTree(root->left, space);
    std::cout << std::endl;
    for (int i = 6; i < space; i++)
    {
        std::cout << " ";
    }
    root->print();
    printTree(root->right, space);
}

template <class T>
void RBTree<T>::printTree()
{
    printTree(this->head, 0);
}
