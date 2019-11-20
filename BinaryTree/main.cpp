#include "BinaryTree.h"

int main()
{
    BinaryTree* tree = new BinaryTree();

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 -1 -1 
    tree->input();

    std::cout <<tree << std::endl;

    tree->levelWise();
    
    
    return 0;
}