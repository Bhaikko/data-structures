#include "VanEmdeTree.h"

int main()
{
    int size = 64; // range = [0, 1, ... 7]
    // Max Range = ceil(sqrt(size));
    VanEmdeTree* tree = new VanEmdeTree(size);
    tree->insert(2);
    tree->insert(3);
    tree->insert(6);
    tree->insert(8);

    std::cout << tree->isMember(3) << std::endl;
    std::cout << tree->isMember(4) << std::endl;

    std::cout << tree->successor(4) << std::endl;
    // std::cout << tree->predecessor(6) << std::endl;

    tree->delete_key(6);
    std::cout << tree->isMember(6) << std::endl;
    std::cout << tree->successor(4) << std::endl;

}