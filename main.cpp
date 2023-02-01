#include "AVLTree/AVLTree.hpp"
#include <iostream>
int main()
{
    Tahsin::AVLTree *tree = new Tahsin::AVLTree();
    tree->Add(4);
    tree->Add(2);
    tree->Add(6);
    std::cout << tree->Balanced();
    return 0;
}