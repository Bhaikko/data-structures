#include "BTree.h"

int main()
{
    BTree t(3); // A B-Tree with minium degree 3 
	t.insert(10); 
	t.insert(20); 
	t.insert(5); 
	t.insert(6); 
	t.insert(12); 
	t.insert(30); 
	t.insert(7); 
	t.insert(17); 

	std::cout << "Traversal of the constucted tree is "; 
	t.traverse(); 

    std::cout << ((t.search(6) != NULL) ? "Present" : "Not Present") << std::endl; 
    std::cout << ((t.search(15) != NULL) ? "Present" : "Not Present") << std::endl; 

	return 0; 
}