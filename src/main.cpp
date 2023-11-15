#include "RBTree.h"

int main() {
    RBTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
//    tree.insert(45);
//    tree.insert(80);
    tree.insert(60);
    tree.printTree();
    return 0;
}