#include "BST.h"

int main()
{
    BST* tree = new BST();

    int input[] = {12, 5, 15, 3, 7, 13, 17, 19, 1, 9};
    int size = 10;

    for (int i = 0; i < 10; i++) {
        tree->insertData(input[i]);
    }

    tree->print();

    tree->deleteData(3);
    std::cout << (tree->search(15) ? "true" : "false") << std::endl;
    tree->deleteData(15);
    std::cout << (tree->search(15) ? "true" : "false") << std::endl;


    return 0;
}