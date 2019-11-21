#include "AVL.h"

int main()
{
    AVL* tree = new AVL();

    tree->insert_data(10);  
    tree->insert_data(20);  
    tree->insert_data(30);  
    tree->insert_data(40);  
    tree->insert_data(50);  
    tree->insert_data(25); 

    tree->print();

    tree->delete_data(10);
    tree->delete_data(20);
    tree->delete_data(25);

    tree->print();
}