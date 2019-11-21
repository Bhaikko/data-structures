#include "RedBlack.h"

// NOT WORKING AS OF NOW
// WILL BE FIXED
int main() 
{ 
	RedBlack* tree = new RedBlack(); 

	tree->insert_data(7); 
	tree->insert_data(6); 
	tree->insert_data(5); 
	tree->insert_data(4); 
	tree->insert_data(3); 
	tree->insert_data(2); 
	tree->insert_data(1); 

    tree->print();

	return 0; 
} 
