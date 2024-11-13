#include "RBTree.h"

int main()
{
    RBTree tree;
    for (int i = 1; i < 16; i++)
    {
        std::cout << "Inserting: " << i << std::endl;
        tree.insert(i);
        tree.printTree();
        std::cout << "____________________________________________" << std::endl;
    }
    return 0;
}
